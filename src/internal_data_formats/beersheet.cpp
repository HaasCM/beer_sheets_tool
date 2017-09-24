/*!
  \file beersheet.cpp
  \brief file to define BeerSheet
*/

#include "beersheet.h"

/*!
  \fn BeerSheet::BeerSheet(QObject *parent, SheetType type)
  \brief Default constructor for BeerSheet
*/

BeerSheet::BeerSheet(SheetType type, QObject *parent) :
QObject(parent),
mSheetType(type){

}

/*!
  \fn BeerSheet::BeerSheet()
  \brief Default destructor for BeerSheet
*/

BeerSheet::~BeerSheet() {

}

/*!
  \fn SheetType BeerSheet::getSheetType() const
  \brief returns the type of beer sheet
*/

SheetType BeerSheet::getSheetType() const {
  return mSheetType;
}

/*!
  \fn ScoringRules BeerSheet::getRules() const
  \brief returns the scoring rules
*/

ScoringRules BeerSheet::getRules(const RuleType type) const {
  switch(type) {
    case RuleType::Passing:
      return mPassingRules;
    case RuleType::Recieving:
      return mReceivingRules;
    case RuleType::Rushing:
      return mRushingRules;
  }
  return ScoringRules();
}

/*!
  \fn PlayerLimits BeerSheet::getLimits() const
  \brief returns the player position limits for the sheet
*/

PlayerLimits BeerSheet::getLimits() const {
  return mTeamLimits;
}

/*!
  \fn void BeerSheet::setRules(const ScoringRules &rules)
  \brief sets the scoring rules for the beer sheet
*/

void BeerSheet::setRules(const ScoringRules &rules, const RuleType type) {
  switch(type) {
    case RuleType::Passing:
      mPassingRules = rules;
      break;
    case RuleType::Recieving:
      mReceivingRules = rules;
      break;
    case RuleType::Rushing:
      mRushingRules = rules;
      break;
  }
}

/*!
  \fn void BeerSheet::setLimits(const PlayerLimits &limits)
  \brief sets the player position limits for the sheet
*/

void BeerSheet::setLimits(const PlayerLimits &limits) {
  mTeamLimits = limits;
}

/*!
  \fn SheetType BeerSheet::stringToSheetType(QString &string) const
  \brief converts a string to a SheetType
*/

SheetType BeerSheet::stringToSheetType(QString string) {
  if(string.toLower() == "snake") {
    return SheetType::Snake;
  } else if(string.toLower() == "auction") {
    return SheetType::Auction;
  } else {
    return SheetType::Custom;
  }
}

/*!
  \brief gets the date of the beersheet
  \return the date the beersheet was updated
*/
QDate BeerSheet::getDate() const{
  return mDate;
}

/*!
  \brief sets the date of the beersheet
  \param date the date to set the beersheet to
*/
void BeerSheet::setDate(const QDate &date){
  mDate = date;
}

void BeerSheet::addPlayer(Player player) {
  mPlayers[player.getPosition()].append(player);
}

/*!
  \fn void BeerSheet::setTeamSize(const int size)
  \brief sets the team size limit
*/

void BeerSheet::setTeamSize(const int size) {
  mTeamSize = size;
}

/*!
  \fn void BeerSheet::setPPR(const int ppr)
  \brief sets the ppr
*/

void BeerSheet::setPPR(const double ppr) {
  mPPR = ppr;
}
