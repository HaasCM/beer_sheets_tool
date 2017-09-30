/*!
  \file player_data_tests.cpp
  \brief file to implement PlayerData type unit tests
*/

#include "player_data.h"

#include <QtTest/QtTest>
#include <numeric>

/*!
  \class PlayerDataTests
  \brief Class to test the PlayerData public interface
*/
class PlayerDataTests : public QObject {
  Q_OBJECT

private slots:
  void checkRank();
  void checkRank_data();

  void checkPerformance();
  void checkPerformance_data();

  void checkValue();
  void checkValue_data();

  void checkPositionalScarcity();
  void checkPositionalScarcity_data();

  void checkDate();
  void checkDate_data();

  void checkEquality();
  void checkEquailty_data();

  void checkInequality();
  void checkInequality_data();

  void checkToQStringMap();
  void checkToQStringMap_data();
};

/*!
  \brief Function to test the rank interface
*/
void PlayerDataTests::checkRank() {
  QFETCH(int, round);
  QFETCH(int, pick);


  QDate date = QDate::currentDate();

  // What this function is testing
  PlayerData::Rank rank;
  rank.round = round;
  rank.pick = pick;

  PlayerData::Performance performance;

  double value = 0;

  int scarcity = 0;

  PlayerData data(date, rank, performance, value, scarcity);

  QVERIFY(rank.pick == data.getRank().pick);
  QVERIFY(rank.round == data.getRank().round);

  //Verify no accidental referencing

  rank.pick = -1;
  rank.round = -1;

  QVERIFY(rank.pick != data.getRank().pick);
  QVERIFY(rank.round != data.getRank().round);

}

/*!
  \brief Function to generate the test matrix for the rank interface tests
*/
void PlayerDataTests::checkRank_data() {
  QTest::addColumn<int>("round");
  QTest::addColumn<int>("pick");

  QTest::newRow("First Round, First Pick")
      << 1 << 1;

  QTest::newRow("Second Round, Third Pick")
      << 2 << 3;

  QTest::newRow("Int MAX, Int MAX")
      << std::numeric_limits<int>().max() << std::numeric_limits<int>().max();

  QTest::newRow("Int MIN, Int MIN")
      << std::numeric_limits<int>().min() << std::numeric_limits<int>().min();

  //TODO add more unit tests
}

/*!
  \brief Function to test the public interface for the performance member
*/
void PlayerDataTests::checkPerformance() {
  QFETCH(int, weeksOneWorthy);
  QFETCH(int, weeksTwoWorthy);
  QFETCH(int, gamesPlayed);

  QDate date = QDate::currentDate();

  PlayerData::Rank rank;

  // What we are testing from this function
  PlayerData::Performance performance;
  performance.weeksOneWorthy = weeksOneWorthy;
  performance.weeksTwoWorthy = weeksTwoWorthy;
  performance.gamesPlayed = gamesPlayed;

  double value = 0;

  int scarcity = 0;

  PlayerData data(date, rank, performance, value, scarcity);

  QVERIFY(performance.weeksOneWorthy == data.getPerformance().weeksOneWorthy);
  QVERIFY(performance.weeksTwoWorthy == data.getPerformance().weeksTwoWorthy);
  QVERIFY(performance.gamesPlayed == data.getPerformance().gamesPlayed);

  performance.weeksOneWorthy = -1;
  performance.weeksTwoWorthy = -1;
  performance.gamesPlayed = -1;

  //Verify no accidental referencing
  QVERIFY(performance.weeksOneWorthy != data.getPerformance().weeksOneWorthy);
  QVERIFY(performance.weeksTwoWorthy != data.getPerformance().weeksTwoWorthy);
  QVERIFY(performance.gamesPlayed != data.getPerformance().gamesPlayed);
}

/*!
  \brief Function to generate the test matrix for the performance member tests.
*/
void PlayerDataTests::checkPerformance_data() {
  QTest::addColumn<int>("weeksOneWorthy");
  QTest::addColumn<int>("weeksTwoWorthy");
  QTest::addColumn<int>("gamesPlayed");

  QTest::addRow("The Perfect Player")
      << 18 << 0 << 18;

  QTest::addRow("The Worst Player")
      << 0 << 0 << 0;

  QTest::addRow("The Mediocre Player")
      << 0 << 18 << 18;
}

/*!
  \brief Function to check the public interface for getting the value
*/
void PlayerDataTests::checkValue() {
  QFETCH(double, value);

  QDate date = QDate::currentDate();

  PlayerData::Rank rank;

  PlayerData::Performance performance;

  int scarcity = 0;

  PlayerData data(date, rank, performance, value, scarcity);

  bool isEqual = qFuzzyCompare(value, data.getValue());
  QVERIFY(isEqual == true);

  value = -1;
  isEqual = qFuzzyCompare(value, data.getValue());
  QVERIFY(isEqual == false);
}

/*!
  \brief Function to generate the test matrix for the value tests
*/
void PlayerDataTests::checkValue_data() {
  QTest::addColumn<double>("value");

  QTest::addRow("0 Value") << 0.; //TODO this is the inital row, need to add more.

  QTest::addRow("1.53 Value") << 1.53;

  QTest::addRow("8.41 Value") << 8.41;
}

void PlayerDataTests::checkPositionalScarcity() {

}

void PlayerDataTests::checkPositionalScarcity_data() {

}

void PlayerDataTests::checkDate() {

}

void PlayerDataTests::checkDate_data() {

}

void PlayerDataTests::checkEquality() {

}

void PlayerDataTests::checkEquailty_data() {

}

void PlayerDataTests::checkInequality() {

}

void PlayerDataTests::checkInequality_data() {

}

void PlayerDataTests::checkToQStringMap() {

}

void PlayerDataTests::checkToQStringMap_data() {

}

QTEST_MAIN(PlayerDataTests)
#include "player_data_tests.moc"
