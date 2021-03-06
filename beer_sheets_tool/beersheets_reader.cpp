/*!
  \file beersheets_reader.cpp
  \brief file to implement BeerSheetsReader
*/

#define LIMIT_REGEX "[(]+[0-9]{2}+[)]|([^0-9])"

#include <memory>

#include "beersheets_reader.h"
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
std::shared_ptr<BeerSheet> BeerSheetsReader::read(const QString &fileName) {
  mFile = new Document(fileName);

  std::shared_ptr<BeerSheet> sheet(new BeerSheet(SheetRules::stringToSheetType(mFile->currentSheet()->sheetName())));
  readHeaderIntoBeerSheet(sheet);

  readPlayers(sheet, QUARTERBACK, 3, 6);
  readPlayers(sheet, RUNNING_BACK, 18, 6);
  readPlayers(sheet, TIGHT_END, 3, 41);
  readPlayers(sheet, WIDE_RECEIVER, 31, 6);
  return sheet;
}

/*!
  \brief Reads the player limits from the QStringlist into the struct
  \param portionedLimits the seperated stringlist of player limits
  \return the appropraite PlayerLimit struct
*/
PlayerLimits BeerSheetsReader::readPlayerLimits(QStringList &portionedLimits) {
  PlayerLimits limits;

  limits.quarterbacks = portionedLimits[3].remove(QRegularExpression(LIMIT_REGEX)).toInt();
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

PlayerData BeerSheetsReader::readPlayerData(int row, PlayerSectionHeader column, const QDate &date) {
  const QStringList rankString = mFile->read(row, column["RNK"]).toString().split(".");
  PlayerData::Rank rank;
  if(rankString.size() == 2) {
    rank.round = rankString[0].toInt();
    rank.pick = rankString[1].toInt();
  } else {
    rank.round = 0;
    rank.pick = 0;
  }

  // Handle the header difference for the tight ends
  const QString performKey = (column.contains("0.5/1/P")) ? "0.5/1/P" : "1/2/P";
  const QStringList performanceString = mFile->read(row, column[performKey]).toString().split("/");

  PlayerData::Performance performance;
  performance.weeksOneWorthy = performanceString[0].toInt();
  performance.weeksTwoWorthy = performanceString[1].toInt();
  performance.gamesPlayed = performanceString[2].toInt();

  double value = mFile->read(row, column["VAL"]).toDouble();

  double scarcityDouble =  mFile->read(row, column["PS"]).toString().toDouble() * 100;
  int scarcity = qRound(scarcityDouble);

  return PlayerData(date, rank, performance, value, scarcity);
}

BeerSheetsReader::PlayerSectionHeader BeerSheetsReader::readPlayerSectionHeader(int row, int col) {
  PlayerSectionHeader header;

  while(!(header.contains("PS"))) {
    QString key = mFile->read(row, col).toString().remove(" (POS)");
    header[key] = col;
    col++;
  }

  return header;
}

/*!
  \fn bool BeerSheetReader::readHeaderIntoSheet(BeerSheet *sheet)
  \brief reads the header into sheet
*/
bool BeerSheetsReader::readHeaderIntoBeerSheet(std::shared_ptr<BeerSheet> sheet) {
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
  SheetRules& sheetRules = sheet->getSheetRules();
  sheetRules.setTeamSize(portions[1].remove(QRegularExpression("[^0-9]")).toInt());
  sheetRules.setPPR(portions[2].remove(QRegularExpression("[^0-9|[.]]")).toDouble());
  sheetRules.setLimits(readPlayerLimits(portions));

  QString rulesBar = mFile->read(2,2).toString();
  QStringList rules = rulesBar.split(QRegularExpression("[|]"));

  if(rules.size() != 4) {
    qCritical() << "Error in reading the rules section!";
    return false;
  }

  sheetRules.setScoringRules(readRules(rules[0]), RuleType::Passing);
  sheetRules.setScoringRules(readRules(rules[1]), RuleType::Rushing);
  sheetRules.setScoringRules(readRules(rules[2]), RuleType::Receiving);

  sheet->setDate(readDate(rules[3]));

  return true;
}

/*!
  \brief attempts to read the players into the program
*/
bool BeerSheetsReader::readPlayers(std::shared_ptr<BeerSheet> sheet, QString position, int col, int row) {
  PlayerSectionHeader column = readPlayerSectionHeader((row - 1), col);

  const QDate& sheetDate = sheet->getDate();

  while(!mFile->read(row, column["NAME"]).toString().isEmpty()) {
    QString playerNameAndDepth = mFile->read(row, column["NAME"]).toString().remove(QRegularExpression("[(]|[)]"));
    QStringList nameAndDepthList = playerNameAndDepth.split(QRegularExpression("[\040](?=[0-9])"));

    bool isStarter = true;
    QString playerName = nameAndDepthList[0].remove(QRegularExpression("[^a-zA-Z\040\-]")).trimmed();
    if(nameAndDepthList.size() == 2) {
      isStarter = (1 == nameAndDepthList[1].toInt());
    }

    QString team = mFile->read(row, column["TM/BW"]).toString().split("/")[0];
    int byeWeek = mFile->read(row, column["TM/BW"]).toString().split("/")[1].toInt();
    Player player(playerName,
                  team,
                  position,
                  byeWeek,
                  isStarter);
    player.addPlayerData(readPlayerData(row, column, sheetDate));

    sheet->addPlayer(player);

    ++row;
  }

  return true;
}

