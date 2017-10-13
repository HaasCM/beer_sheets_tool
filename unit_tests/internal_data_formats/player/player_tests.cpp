/*!
  \file player_tests.cpp
  \brief file to define and implement player unit tests
*/

#include <QtTest/QtTest>

#include "player.h"
#include "common.h"


/*!
  \class PlayerTests
  \brief Class to test the Player public interface
*/
class PlayerTests : public QObject {
  Q_OBJECT

private slots:
  void setUp();

  void checkName();
  void checkName_data();

  void checkTeam();
  void checkTeam_data();

  void checkPosition();
  void checkPosition_data();

  void checkByeWeek();
  void checkByeWeek_data();

  void checkStarter();
  void checkStarter_data();

  void checkPlayerData();
  void checkPlayerData_data();

  void checkToQStringMap();
  void checkToQStringMap_data();
};

/*!
  \brief Slot to set up metatype registers for testing
*/
void PlayerTests::setUp() {
  qRegisterMetaType<PlayerData::Rank>("Rank");
  qRegisterMetaType<PlayerData::Performance>("Performance");
  qRegisterMetaType<Common::NFLTeam>("NFLTeam");
  qRegisterMetaType<Common::Position>("Position");
}

/*!
  \brief Test driver for the player name interface
*/
void PlayerTests::checkName() {
  QFETCH(QString, name);

  QString team("Free Agent");
  QString position("Running Back");
  int byeWeek(5);
  bool isStarter(true);

  Player player(name, team, position, byeWeek, isStarter);

  QVERIFY(player.getName() == name);

  name = "No Name";

  QVERIFY(player.getName() != name);
}

/*!
  \brief Slot to generate data for the name tests
*/
void PlayerTests::checkName_data() {
  QTest::addColumn<QString>("name");

  QTest::newRow("Invalid Name")   << "";

  QTest::newRow("Aaron Rodgers")  << "Aaron Rodgers";

  QTest::newRow("David Johnson")  << "David Johnson";

  QTest::newRow("Leveon Bell")    << "Leveon Bell";

  QTest::newRow("Rob Gronkowski") << "Rob Gronkowski";

  QTest::newRow("John Brown")     << "John Brown";
}

/*!
  \brief Slot to drive the team interface
*/
void PlayerTests::checkTeam() {
  QFETCH(QString, actual);
  QFETCH(Common::NFLTeam, expected);

  QString name("Name");
  QString position("Running Back");
  int byeWeek(5);
  bool isStarter(true);

  Player player(name, actual, position, byeWeek, isStarter);

  QVERIFY(player.getTeam() == expected);
}

/*!
  \brief Slot to generate the data for the team interface test
*/
void PlayerTests::checkTeam_data() {
  QTest::addColumn<QString>("actual");
  QTest::addColumn<Common::NFLTeam>("expected");

  QTest::newRow("Green Bay") << "gb" << Common::NFLTeam::Packers;

  QTest::newRow("NYJ") << "NYJ" << Common::NFLTeam::Jets;

  QTest::newRow("NYG") << "NYG" << Common::NFLTeam::Giants;

  QTest::newRow("Invalid") << "" << Common::NFLTeam::FreeAgent;

  QTest::newRow("Houston") << "HOU" << Common::NFLTeam::Texans;
}

void PlayerTests::checkPosition() {

}

void PlayerTests::checkPosition_data() {

}

void PlayerTests::checkByeWeek() {

}

void PlayerTests::checkByeWeek_data() {

}

void PlayerTests::checkStarter() {

}

void PlayerTests::checkStarter_data() {

}

void PlayerTests::checkPlayerData() {

}

void PlayerTests::checkPlayerData_data() {

}

void PlayerTests::checkToQStringMap() {

}

void PlayerTests::checkToQStringMap_data() {

}

QTEST_MAIN(PlayerTests)
#include "player_tests.moc"
