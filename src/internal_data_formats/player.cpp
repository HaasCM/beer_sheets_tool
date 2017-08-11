/*!
  \file player.cpp
  \brief file to define Player
*/

#include "player.h"

/*!
  \fn Player::Player(QObject *parent=nullptr)
  \brief Default constructor for Player
*/

Player::Player(){

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
  \fn bool Player::isAStarter() const
  \brief returns true if the player is a starter, else false
*/

bool Player::isAStarter() const {
  return mIsStarter;
}
