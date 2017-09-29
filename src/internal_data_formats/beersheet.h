/*!
  \file beersheet.h
  \brief file to define BeerSheet
*/

#ifndef BEERSHEET_H
#define BEERSHEET_H

#include "player.h"
#include "sheet_rules.h"
#include "common.h"

#include <QtCore>
#include <memory>

/*!
  \class BeerSheet
  \brief class to contain info for one beersheet
*/

class BeerSheet : public QObject{
  Q_OBJECT

public:
  typedef QMap<Common::Position, QList<Player>> Players;

  BeerSheet(SheetType type=SheetType::Snake, QObject *parent=nullptr);
  ~BeerSheet();

  const SheetRules& getSheetRules() const;
  SheetRules& getSheetRules();
  QDate getDate() const;

  void setDate(const QDate &date);

  void addPlayer(Player player);

  static SheetType stringToSheetType(QString string);

protected:

private:
  QDate mDate; //!< the QDate that this sheet was updated
  SheetRules mRules; //!< Rules for this beersheet
  Players mPlayers; //!< The players contained in this sheet

};

#endif //BEERSHEET_H
