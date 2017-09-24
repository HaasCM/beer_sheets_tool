/*!
  \file beersheets_reader.h
  \brief file to define BeerSheetsReader
*/

#ifndef BEERSHEETS_READER_H
#define BEERSHEETS_READER_H

#include <QtCore>
#include <QtXlsx>

#include "player.h"
#include "beersheet.h"
#include "player_column.h"

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

  BeerSheet* read(const QString &fileName);

protected:

private:
  PlayerLimits readPlayerLimits(QStringList &portionedLimits);
  ScoringRules readRules(QString &rulesString);
  QDate readDate(QString &date);
  PlayerData readPlayerData(int row, PlayerColumn column, const QDate &date);

  bool readHeaderIntoBeerSheet(BeerSheet *sheet);
  bool readPlayers(BeerSheet *sheet, QString position, int col, int row);

  Document* mFile = nullptr;

};

#endif //BEERSHEETS_READER_H
