/*!
  \file player.cpp
  \brief file to define Player
*/

#include "player.h"

/*!
  \fn Player::Player(QObject *parent=nullptr)
  \brief Default constructor for Player
*/

Player::Player(const QString name, const QString team, const QString position, const int byeWeek, const bool isStarter):
mName(name),
mByeWeek(byeWeek),
mIsStarter(isStarter){
  mTeam = mEnumHandler.translateTeam(team);
  mPosition = mEnumHandler.translatePosition(position);
}

/*!
  \fn Player::Player()
  \brief Default destructor for Player
*/

Player::~Player() {
}

/*!
  \fn QString Player::getName() const
  \brief returns the name of the player
*/

QString Player::getName() const {
  return mName;
}

/*!
  \fn Common::NFLTeam Player::getTeam() const
  \brief returns the player's current team
*/

Common::NFLTeam Player::getTeam() const {
  return mTeam;
}

/*!
  \fn Common::Position Player::getPosition() const
  \brief returns the player's current position
*/

Common::Position Player::getPosition() const {
  return mPosition;
}

/*!
  \fn int Player::getByeWeek() const
  \brief returns the bye week for the player
*/

int Player::getByeWeek() const {
  return mByeWeek;
}

/*!
  \brief returns the player data points
  \return returns the player data points
*/
QList<PlayerData> Player::getPlayerData() const {
  return mPlayerDataPoints;
}

/*!
  \fn bool Player::isAStarter() const
  \brief returns true if the player is a starter, else false
*/

bool Player::isAStarter() const {
  return mIsStarter;
}

/*!
  \brief appends a PlayerData value to the end of the player data list
  \param data the data to be appended
*/
void Player::addPlayerData(PlayerData &data) {
  mPlayerDataPoints.append(data);
}

/*!
  \brief converts the player to a qstringmap for debugging
  \return
*/
QStringMap Player::toQStringMap() const {
  QStringMap map;

  map["Player Name"] = mName;
  map["Team Name"] = Common::NFLEnumHandler::instance().translateTeam(mTeam);
  map["Position"] = Common::NFLEnumHandler::instance().translatePosition(mPosition);
  map["Is a Starter?"] = (mIsStarter) ? ("Yes") : ("No");
  map["Bye Week"] = QString::number(mByeWeek);

  return map;
}
