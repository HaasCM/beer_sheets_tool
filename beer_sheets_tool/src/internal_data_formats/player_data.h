/*!
  \file player_data.h
  \brief file to define the PlayerData class
*/

#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

#include <QDate>
#include <QDebug>
#include <QMap>

typedef QMap<QString, QString> QStringMap;

/*!
  \brief Class to store PlayerData information
*/
class PlayerData {
public:

  /*!
    \brief Struct to store the ADP of the player in BeerSheetsFormat
  */

  typedef struct {
    int round; //!< the round the player is projected to be drafted
    int pick; //!< Pick within the round the player is projected to be drafted
  } Rank;

  /*!
    \brief Struct to store the performance data
  */
  typedef struct {
    int weeksOneWorthy; //!< weeks the player was worthy of starting
    int weeksTwoWorthy; //!< weeks the player was worthy of a secondary
    int gamesPlayed; //!< weeks the player played
  } Performance;

  explicit PlayerData(const QDate &date, Rank &rank, Performance &performance, double &value, int &posScarcity);
  ~PlayerData();

  Rank getRank() const;
  Performance getPerformance() const;
  double getValue() const;
  int getPositionalScarcity() const;

  QDate getDate() const;

  bool operator==(const PlayerData &other) const;
  bool operator!=(const PlayerData &other) const;

  QStringMap toQStringMap() const;

private:
  QDate mDateStamp; //!< datestamp for the specific datapoint

  Rank mRank; //!< The Rank of the player
  Performance mPerformance; //!< The performance of the player
  double mValue; //!< Value of the player for the beersheet
  int mScarcity; //!< Positional Scarcity for the draft
};
#endif // PLAYER_DATA_H
