/*!
  \file player_data.h
  \brief file to define the PlayerData class
*/

#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

/*!
  \brief macro for the timestamp key used in toQStringMap()
*/
#define TIME_STAMP_KEY    "TimeStamp"
/*!
  \brief macro for the Round key used in toQStringMap()
*/
#define ROUND_KEY         "Round"
/*!
  \brief macro for the Pick key used in toQStringMap()
*/
#define PICK_KEY          "Pick"
/*!
  \brief macro for the weeks worthy of a start key used in toQStringMap()
*/
#define WEEKS_ONE_KEY     "Weeks Worthy of First"
/*!
  \brief macro for the weeks worthy of a secondary key used in toQStringMap()
*/
#define WEEKS_TWO_KEY     "Weeks Worthy of Second"
/*!
  \brief macro for the total games played key used in toQStringMap()
*/
#define GAMES_PLAYED_KEY  "Games Played"
/*!
  \brief macro for the value key used in toQStringMap()
*/
#define VALUE_KEY         "Value"
/*!
  \brief macro for the Positional Scarcity key used in toQStringMap()
*/
#define PS_KEY            "Positional Scarcity"

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
