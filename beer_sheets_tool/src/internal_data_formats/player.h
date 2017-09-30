/*!
  \file player.h
  \brief file to define Player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "common/common.h"
#include "player_data.h"

/*!
  \class Player
  \brief Class to describe the NFL Player
*/
class Player {

public:
  Player(const QString name, const QString team, const QString position, const int byeWeek, const bool isStarter);
  ~Player();

  QString getName() const;
  Common::NFLTeam getTeam() const;
  Common::Position getPosition() const;
  int getByeWeek() const;
  QList<PlayerData> getPlayerData() const;

  bool isAStarter() const;

  void addPlayerData(PlayerData data);

  QStringMap toQStringMap() const;


protected:

private:
  QString mName; //!< Human readable name of the player
  Common::NFLTeam mTeam; //!< enum for the player team
  Common::Position mPosition; //!< enum for the position the player plays
  Common::NFLEnumHandler &mEnumHandler = Common::NFLEnumHandler::instance(); //!< reference to the Common::NFLEnumHandler instance.
  int mByeWeek; //!< Bye week for the player
  bool mIsStarter; //!< is a starter for their team

  QList<PlayerData> mPlayerDataPoints; //!< QVector to store the player datapoints
};

#endif //PLAYER_H
