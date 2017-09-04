/*!
  \file player.h
  \brief file to define Player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

/*
 * A player has
 *    One name
 *    One current team
 *    One current draftable position
 *    One bye week for the current year
 *    One flag for a starter
 *
 *    PLACE THIS INTO A PLAYER INFO CLASS?
 *      Multiple ranks dependent on the date
 *      Multiple Games played depending on the year
 *      Multiple values depending on the day
 *      Multiple position scarcity depending on the date
 *
*/

/*
typedef struct {
  int primary; //!< depicts the round they should be chosen in
  int secondary; //!< depicts the slot in the round they should be chosen in
} Rank;
*/

class Player{

public:
  Player(const QString name, const QString team, const QString position, const int byeWeek, const bool isStarter);
  ~Player();

  QString getName() const;
  Common::NFLTeam getTeam() const;
  Common::Position getPosition() const;
  int getByeWeek() const;

  bool isAStarter() const;



protected:

private:
  QString mName; //!< Human readable name of the player
  Common::NFLTeam mTeam; //!< enum for the player team
  Common::Position mPosition; //!< enum for the position the player plays
  Common::NFLEnumHandler& mEnumHandler = Common::NFLEnumHandler::instance();
  int mByeWeek; //!< Bye week for the player
  bool mIsStarter; //!< is a starter for their team
  //QVector to store a struct of the below information and a date?

  //Break these out!
  /*
  Rank mRank; //!< rank structure for the player
  int mGamesPlayed; //!< Total number of weeks played
  double mValue; //!< value of the player
  int mPositionalScarcity; //!< Scarcity of players at that positon.
*/
};

#endif //PLAYER_H
