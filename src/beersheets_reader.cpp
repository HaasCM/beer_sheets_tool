/*!
  \file beersheets_reader.cpp
  \brief file to define BeerSheetsReader
*/

#define LIMIT_REGEX "[(]+[0-9]{2}+[)]|([^0-9])"

#include "beersheets_reader.h"
#include "playercolumn.h"
#include "player.h"

using namespace QXlsx;

/*!
  \fn BeerSheetsReader::BeerSheetsReader(QObject *parent)
  \brief Default constructor for BeerSheetsReader
*/

BeerSheetsReader::BeerSheetsReader(QObject *parent) :
QObject(parent){
}

/*!
  \fn BeerSheetsReader::BeerSheetsReader()
  \brief Default destructor for BeerSheetsReader
*/

BeerSheetsReader::~BeerSheetsReader() {

}

/*!
  \fn BeerSheet BeerSheetsReader::read(const QString &fileName)
  \brief reads the beersheet into memory
*/

BeerSheet *BeerSheetsReader::read(const QString &fileName) {
  mFile = new Document(fileName);
  BeerSheet *sheet = new BeerSheet(BeerSheet::stringToSheetType(mFile->currentSheet()->sheetName()));
  readHeaderIntoBeerSheet(sheet);

  readQuarterbacks(sheet);
  return sheet;
}

/*!
  \fn bool BeerSheetReader::readHeaderIntoSheet(BeerSheet *sheet)
  \brief reads the header into sheet
*/

bool BeerSheetsReader::readHeaderIntoBeerSheet(BeerSheet *sheet) {
  QString titleBar = mFile->read(1, 2).toString();
  if(!titleBar.contains("BeerSheet", Qt::CaseInsensitive)) {
    qCritical() << "File is not a beer sheet!";
    return false;
  }
  PlayerLimits limits;
  QStringList portions = titleBar.split(QRegularExpression("[-/]"));

  if(portions.size() != 10) {
    qCritical() << "Header size is not 10 elements!";
    return false;
  }

  sheet->setTeamSize(portions[1].remove(QRegularExpression("[^0-9]")).toInt());
  sheet->setPPR(portions[2].remove(QRegularExpression("[^0-9|[.]]")).toDouble());

  limits.quarterBacks = portions[3].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.runningBacks = portions[4].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.wideReceivers = portions[5].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.tightEnds = portions[6].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.flexes = portions[7].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.DST = portions[8].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.PK = portions[9].remove(QRegularExpression(LIMIT_REGEX)).toInt();

  sheet->setLimits(limits);

  QString rulesBar = mFile->read(2,2).toString();
  QStringList rules = rulesBar.split(QRegularExpression("[|]"));
  if(rules.size() != 4) {
    qCritical() << "Error in reading the rules section!";
    return false;
  }
  auto readRulesSection = [&](ScoringRules ruleStruct, int section) {
    Q_UNUSED(ruleStruct)
    QStringList rulesList = rules[section].remove(QRegularExpression("[^0-9|[.]]")).split(" ");
    rulesList.removeAll("");
    if(rulesList.size() < 2) {
      return false;
    } else {
    ruleStruct.pointsPerTD = rulesList[1].toInt();
    ruleStruct.pointsPerYard = rulesList[2].toDouble();
    }
    return true;
  };
  ScoringRules passing, rushing, receiving;
  if(!readRulesSection(passing, 0)) {
    qCritical() << "Could not read the Passing rules!";
    return false;
  } else if(!readRulesSection(rushing, 1)) {
    qCritical() << "Could not read the Rushing rules!";
    return false;
  } else if(!readRulesSection(receiving, 2)) {
    qCritical() << "Could not read the Receiving rules!";
    return false;
  }
  sheet->setRules(passing, RuleType::Passing);
  sheet->setRules(rushing, RuleType::Rushing);
  sheet->setRules(receiving, RuleType::Recieving);

  return true;
}

/*!
  \fn bool BeerSheetsReader::readQuarterbacks(BeerSheet *sheet)
  \brief attempts to read the quarterbacks into the program
*/
bool BeerSheetsReader::readQuarterbacks(BeerSheet *sheet) {
  int quarterbackRow = 6;
  PlayerColumn PlayerColumn(3);
  while(!mFile->read(quarterbackRow, 3).toString().isEmpty()) {
    QString playerName = mFile->read(quarterbackRow, PlayerColumn.name()).toString();
    QString team = mFile->read(quarterbackRow, PlayerColumn.team()).toString().split("/")[0];
    int byeWeek = mFile->read(quarterbackRow, PlayerColumn.team()).toString().split("/")[1].toInt();
    double rank = mFile->read(quarterbackRow, PlayerColumn.rank()).toString().toDouble();
    QString playedData =  mFile->read(quarterbackRow, PlayerColumn.played()).toString();
    double value = mFile->read(quarterbackRow, PlayerColumn.value()).toString().toDouble();
    double scarcity = (mFile->read(quarterbackRow, PlayerColumn.scarcity()).toString().remove("%")).toDouble();
    Player player(playerName,
                  team,
                  QUARTERBACK,
                  byeWeek,
                  true);
    qDebug() << player.toQStringMap();

    ++quarterbackRow;
  }
}
