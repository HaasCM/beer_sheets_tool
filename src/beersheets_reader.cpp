/*!
  \file beersheets_reader.cpp
  \brief file to define BeerSheetsReader
*/

#define LIMIT_REGEX "[(]+[0-9]{2}+[)]|([^0-9])"

#include "beersheets_reader.h"
#include "player_column.h"
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

  readPlayers(sheet, QUARTERBACK, 3, 6);
  return sheet;
}

/*!
  \brief Reads the player limits from the QStringlist into the struct
  \param portionedLimits the seperated stringlist of player limits
  \return the appropraite PlayerLimit struct
*/
PlayerLimits BeerSheetsReader::readPlayerLimits(QStringList &portionedLimits) {
  PlayerLimits limits;

  limits.quarterBacks = portionedLimits[3].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.runningBacks = portionedLimits[4].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.wideReceivers = portionedLimits[5].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.tightEnds = portionedLimits[6].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.flexes = portionedLimits[7].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.DST = portionedLimits[8].remove(QRegularExpression(LIMIT_REGEX)).toInt();
  limits.PK = portionedLimits[9].remove(QRegularExpression(LIMIT_REGEX)).toInt();

  return limits;
}

/*!
  \brief Reads the rules from the string and assigns the values into the struct
  \param rulesString the string of rules to read in
  \return The scoring rules struct that was read in
*/
ScoringRules BeerSheetsReader::readRules(QString &rulesString) {
  QStringList rulesList = rulesString.remove(QRegularExpression("[^0-9|[.]]")).split(" ");
  rulesList.removeAll("");

  Q_ASSERT(rulesList.size() < 2);

  ScoringRules rules;
  rules.pointsPerTD = rulesList[1].toInt();
  rules.pointsPerYard = rulesList[2].toDouble();

  return rules;
}

/*!
  \brief BeerSheetsReader::readDate
  \param date
  \return
*/
QDate BeerSheetsReader::readDate(QString &date) {
  QStringList dateList = date.split("-");

  // remove all but numbers
  dateList[0].remove(QRegularExpression("[^0-9]"));

  const int year = dateList[0].toInt();
  const int month = dateList[1].toInt();
  const int day = dateList[2].toInt();

  return QDate(year, month, day);

}

PlayerData BeerSheetsReader::readPlayerData(int row, PlayerColumn column, const QDate &date) {
  const QStringList rankString = mFile->read(row, column.rank()).toString().split(".");
  PlayerData::Rank rank;
  rank.round = rankString[0].toInt();
  rank.pick = rankString[1].toInt();

  const QStringList performanceString = mFile->read(row, column.played()).toString().split("/");
  PlayerData::Performance performance;
  performance.weeksOneWorthy = performanceString[0].toInt();
  performance.weeksTwoWorthy = performanceString[1].toInt();
  performance.gamesPlayed = performanceString[2].toInt();

  double value = mFile->read(row, column.value()).toString().toDouble();

  double scarcityDouble =  mFile->read(row, column.scarcity()).toString().toDouble() * 100;
  int scarcity = qRound(scarcityDouble);

  return PlayerData(date, rank, performance, value, scarcity);
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

  QStringList portions = titleBar.split(QRegularExpression("[-/]"));

  if(portions.size() != 10) {
    qCritical() << "Header size is not 10 elements!";
    return false;
  }

  sheet->setTeamSize(portions[1].remove(QRegularExpression("[^0-9]")).toInt());
  sheet->setPPR(portions[2].remove(QRegularExpression("[^0-9|[.]]")).toDouble());
  sheet->setLimits(readPlayerLimits(portions));

  QString rulesBar = mFile->read(2,2).toString();
  QStringList rules = rulesBar.split(QRegularExpression("[|]"));

  if(rules.size() != 4) {
    qCritical() << "Error in reading the rules section!";
    return false;
  }

  sheet->setRules(readRules(rules[0]), RuleType::Passing);
  sheet->setRules(readRules(rules[1]), RuleType::Rushing);
  sheet->setRules(readRules(rules[2]), RuleType::Recieving);

  sheet->setDate(readDate(rules[3]));

  return true;
}

/*!
  \brief attempts to read the players into the program
*/
bool BeerSheetsReader::readPlayers(BeerSheet *sheet, QString position, int col, int row) {
  PlayerColumn column(col);
  const QDate& sheetDate = sheet->getDate();
  while(!mFile->read(row, 3).toString().isEmpty()) {
    QString playerName = mFile->read(row, column.name()).toString();
    QString team = mFile->read(row, column.team()).toString().split("/")[0];
    int byeWeek = mFile->read(row, column.team()).toString().split("/")[1].toInt();
    Player player(playerName,
                  team,
                  position,
                  byeWeek,
                  true);
    player.addPlayerData(readPlayerData(row, column, sheetDate));

    sheet->addPlayer(player);

    ++row;
  }

  return true;
}

