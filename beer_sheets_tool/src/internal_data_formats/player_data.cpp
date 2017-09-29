/*!
  \file player_data.cpp
  \brief file to implement the PlayerData class
*/

#include "player_data.h"

/*!
  \brief Default constructor for the PlayerData object
  \param rank rank structure for the given data point
  \param performance performance structure for the given data point
  \param value value for the given data point
  \param posScarcity positional scarcity value for the given player
  \param date datestamp for the datapoint
*/
PlayerData::PlayerData(const QDate &date, PlayerData::Rank &rank, PlayerData::Performance &performance, double &value, int &posScarcity) :
mDateStamp(date),
mRank(rank),
mPerformance(performance),
mValue(value),
mScarcity(posScarcity){
  //assert statements to check values during debuging
  Q_ASSERT((mDateStamp.isValid()));

  Q_ASSERT(mRank.pick > 0);
  Q_ASSERT(mRank.round > 0);

  Q_ASSERT(mPerformance.weeksOneWorthy >= 0);
  Q_ASSERT(mPerformance.weeksTwoWorthy >= 0);
  Q_ASSERT((mPerformance.gamesPlayed >= 0 && mPerformance.gamesPlayed <= 15));

  Q_ASSERT((mValue > 0.));

  Q_ASSERT((mScarcity >= 0 && mScarcity < 100));
}

/*!
  \brief Destructor for player data
*/
PlayerData::~PlayerData() {

}

/*!
  \brief gets the rank for the data point
  \return the associated rank struct
 */
PlayerData::Rank PlayerData::getRank() const {
  return mRank;
}

/*!
  \brief gets the performance struct for the data point
  \return the performance struct
*/
PlayerData::Performance PlayerData::getPerformance() const {
  return mPerformance;
}

/*!
  \brief returns the value of the data point
  \return double value of the data point
*/
double PlayerData::getValue() const {
  return mValue;
}

/*!
  \brief returns the positional scarcity
  \return integer value for positional scarcity
*/
int PlayerData::getPositionalScarcity() const {
  return mScarcity;
}

/*!
  \brief gets the date stamp for the data point
  \return returns a date stamp for the data point
*/
QDate PlayerData::getDate() const {
  return mDateStamp;
}

/*!
  \brief compares this data point to another
  \param other the other data point to compare
  \return returns true if the two data points are the same
*/
bool PlayerData::operator==(const PlayerData &other) const {
  return(this->mDateStamp                  == other.mDateStamp                  &&
         this->mRank.round                 == other.mRank.round                 &&
         this->mRank.pick                  == other.mRank.pick                  &&
         this->mPerformance.weeksOneWorthy == other.mPerformance.weeksOneWorthy &&
         this->mPerformance.weeksTwoWorthy == other.mPerformance.weeksTwoWorthy &&
         this->mPerformance.gamesPlayed    == other.mPerformance.gamesPlayed    &&
         qFuzzyCompare(this->mValue, other.mValue)                              &&
         this->mScarcity                   == other.mScarcity);
}

/*!
  \brief compares this data point to another
  \param other the other data point to compare against
  \return returns true if the two data points are not the same
*/
bool PlayerData::operator!=(const PlayerData &other) const {
  return(!(*(this) == other));
}

/*!
  \brief Converts the data point to a QString map
  \return returns a QStringmap with the member data in it
*/
QStringMap PlayerData::toQStringMap() const {
  QStringMap map;

  map["Time Stamp"] = this->mDateStamp.toString();
  map["Round"] = QString::number(this->mRank.round);
  map["Pick"] = QString::number(this->mRank.pick);
  map["Weeks Worthy of First"] = QString::number(this->mPerformance.weeksOneWorthy);
  map["Weeks Worthy of Second"] = QString::number(this->mPerformance.weeksTwoWorthy);
  map["Games Played"] = QString::number(this->mPerformance.gamesPlayed);
  map["Value"] = QString::number(this->mValue);
  map["Positional Scarcity"] = QString::number(this->mScarcity);

  return map;
}






