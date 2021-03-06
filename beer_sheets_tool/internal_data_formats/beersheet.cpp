/*!
  \file beersheet.cpp
  \brief file to implement BeerSheet
*/

#include "beersheet.h"

/*!
  \fn BeerSheet::BeerSheet(QObject *parent, SheetType type)
  \brief Default constructor for BeerSheet
*/

BeerSheet::BeerSheet(SheetType type, QObject *parent) :
QObject(parent),
mRules(type) {
}

/*!
  \fn BeerSheet::BeerSheet()
  \brief Default destructor for BeerSheet
*/

BeerSheet::~BeerSheet() {

}

/*!
  \brief gets the sheet rules
  \return returns a non editable reference to the sheet rules
*/
const SheetRules& BeerSheet::getSheetRules() const {
  return mRules;
}

/*!
  \brief gets the sheet rules
  \return returns an editable reference to the sheet rules
*/
SheetRules& BeerSheet::getSheetRules() {
  return mRules;
}

/*!
  \brief gets the date of the beersheet
  \return the date the beersheet was updated
*/
QDate BeerSheet::getDate() const {
  return mDate;
}


/*!
  \brief sets the date of the beersheet
  \param date the date to set the beersheet to
*/
void BeerSheet::setDate(const QDate &date) {
  mDate = date;
}

void BeerSheet::addPlayer(Player player) {
  mPlayers[player.getPosition()].append(player);
}
