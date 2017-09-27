/*!
  \file beersheets_reader.h
  \brief file to define BeerSheetsReader
*/

#ifndef BEERSHEETS_READER_H
#define BEERSHEETS_READER_H

#include <QtCore>
#include <QtXlsx>
#include <memory>

#include "player.h"
#include "beersheet.h"

using namespace QXlsx;

/*!
  \class BeerSheetsReader
  \brief Class to read in Beersheet
 */
class BeerSheetsReader : public QObject {
  Q_OBJECT

public:
  BeerSheetsReader(QObject *parent = nullptr);
  ~BeerSheetsReader();

  std::shared_ptr<BeerSheet> read(const QString &fileName);

protected:

private:
  typedef QMap<QString, int> PlayerSectionHeader;

  PlayerLimits readPlayerLimits(QStringList &portionedLimits);
  ScoringRules readRules(QString &rulesString);
  QDate readDate(QString &date);
  PlayerData readPlayerData(int row, PlayerSectionHeader column, const QDate &date);
  PlayerSectionHeader readPlayerSectionHeader(int row, int col);

  bool readHeaderIntoBeerSheet(std::shared_ptr<BeerSheet> sheet);
  bool readPlayers(std::shared_ptr<BeerSheet> sheet, QString position, int col, int row);

  Document* mFile = nullptr;

};

#endif //BEERSHEETS_READER_H
