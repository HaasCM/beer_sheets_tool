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
  void checkEquality_data();

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

  rank.pick += 1;
  rank.round += 1;

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

  performance.weeksOneWorthy += 1;
  performance.weeksTwoWorthy += 1;
  performance.gamesPlayed += 1;

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

  value += 1;
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

/*!
  \brief Function to test the positional scarcity of the
*/
void PlayerDataTests::checkPositionalScarcity() {
  QFETCH(int, posScarcity);

  double value;

  QDate date = QDate::currentDate();

  PlayerData::Rank rank;

  PlayerData::Performance performance;

  PlayerData data(date, rank, performance, value, posScarcity);

  QVERIFY(posScarcity == data.getPositionalScarcity());

  posScarcity += 1;

  QVERIFY(posScarcity != data.getPositionalScarcity());
}

/*!
  \brief Function to generate data for the positional scarcity test
*/
void PlayerDataTests::checkPositionalScarcity_data() {
  QTest::addColumn<int>("posScarcity");

  QTest::addRow("0 Scarcity") << 0;

  QTest::addRow("99 Scarcity") << 99;

  QTest::addRow("50 Scarcity") << 50;
}

/*!
  \brief Function to date public interface
*/
void PlayerDataTests::checkDate() {
  QFETCH(QDate, date);

  double value;

  int posScarcity;

  PlayerData::Rank rank;

  PlayerData::Performance performance;

  PlayerData data(date, rank, performance, value, posScarcity);

  QVERIFY(date == data.getDate());

  date = date.addDays(1);

  QVERIFY(date != data.getDate());
}

/*!
  \brief Function to generate the data for the date interface tests
*/
void PlayerDataTests::checkDate_data() {
  QTest::addColumn<QDate>("date");

  QTest::addRow("Current Date") << QDate::currentDate();

  QTest::addRow("August 10 2017") << QDate(2017, 8, 10); // yyyy, mm, dd

  QTest::addRow("September 23 2015") << QDate(2015, 9, 23);

  QTest::addRow("August 24 2016") << QDate(2016, 8, 24);
}

/*!
  \brief Function to test the equality operator
*/
void PlayerDataTests::checkEquality() {
  QFETCH(QDate, date);
  QFETCH(int, round);
  QFETCH(int, pick);
  QFETCH(int, weeksOneWorthy);
  QFETCH(int, weeksTwoWorthy);
  QFETCH(int, gamesPlayed);
  QFETCH(double, value);
  QFETCH(int, posScarcity);

  PlayerData::Rank rank;
  rank.round = round;
  rank.pick = pick;

  PlayerData::Performance performance;
  performance.weeksOneWorthy = weeksOneWorthy;
  performance.weeksTwoWorthy = weeksTwoWorthy;
  performance.gamesPlayed = gamesPlayed;

  PlayerData dataLHS(date, rank, performance, value, posScarcity);
  PlayerData dataRHS(date, rank, performance, value, posScarcity);

  QVERIFY(dataLHS == dataRHS);
  QVERIFY((dataLHS != dataRHS) == false);
}

/*!
  \brief Function to generate data for the equality operator tests
*/
void PlayerDataTests::checkEquality_data() {
  QTest::addColumn<QDate>("date");
  QTest::addColumn<int>("round");
  QTest::addColumn<int>("pick");
  QTest::addColumn<int>("weeksOneWorthy");
  QTest::addColumn<int>("weeksTwoWorthy");
  QTest::addColumn<int>("gamesPlayed");
  QTest::addColumn<double>("value");
  QTest::addColumn<int>("posScarcity");

  QTest::addRow("Null Data")
      << QDate::currentDate() << 0 << 0 << 0 << 0 << 0 << 0. << 0;

  QTest::addRow("Star Player")
      << QDate(2017, 9, 1) << 1 << 1 << 18 << 0 << 18 << 8.6 << 99;

  QTest::addRow("Player (Null Date)")
      << QDate() << 0 << 0 << 0 << 0 << 0 << 0. << 0;

  QTest::addRow("Medoirce Player")
      << QDate::currentDate() << 5 << 12 << 3 << 15 << 18 << 4.5 << 50;
}

/*!
  \brief Function to test teh inequality operator
*/
void PlayerDataTests::checkInequality() {
  QFETCH(QDate, date);
  QFETCH(int, round);
  QFETCH(int, pick);
  QFETCH(int, weeksOneWorthy);
  QFETCH(int, weeksTwoWorthy);
  QFETCH(int, gamesPlayed);
  QFETCH(double, value);
  QFETCH(int, posScarcity);

  PlayerData::Rank rank;
  rank.round = round;
  rank.pick = pick;

  PlayerData::Performance performance;
  performance.weeksOneWorthy = weeksOneWorthy;
  performance.weeksTwoWorthy = weeksTwoWorthy;
  performance.gamesPlayed = gamesPlayed;

  PlayerData dataLHS(date, rank, performance, value, posScarcity);

  date = date.addDays(1);

  rank.round += 1;
  rank.pick += 1;

  performance.weeksOneWorthy += 1;
  performance.weeksTwoWorthy += 1;
  performance.gamesPlayed += 1;

  value += 1;
  posScarcity += 1;
  PlayerData dataRHS(date, rank, performance, value, posScarcity);

  QVERIFY((dataLHS == dataRHS) == false);
  QVERIFY(dataLHS != dataRHS);
}

/*!
  \brief Function to generate the data for the inequality tests
*/
void PlayerDataTests::checkInequality_data() {
  QTest::addColumn<QDate>("date");
  QTest::addColumn<int>("round");
  QTest::addColumn<int>("pick");
  QTest::addColumn<int>("weeksOneWorthy");
  QTest::addColumn<int>("weeksTwoWorthy");
  QTest::addColumn<int>("gamesPlayed");
  QTest::addColumn<double>("value");
  QTest::addColumn<int>("posScarcity");

  QTest::addRow("Null Data")
      << QDate::currentDate() << 0 << 0 << 0 << 0 << 0 << 0. << 0;

  QTest::addRow("Star Player")
      << QDate(2017, 9, 1) << 1 << 1 << 18 << 0 << 18 << 8.6 << 99;

  QTest::addRow("Player (Null Date)")
      << QDate() << 0 << 0 << 0 << 0 << 0 << 0. << 0;

  QTest::addRow("Medoirce Player")
      << QDate::currentDate() << 5 << 12 << 3 << 15 << 18 << 4.5 << 50;
}

/*!
  \brief Function to test the toQStringMap function
*/
void PlayerDataTests::checkToQStringMap() {
  QFETCH(QDate, date);
  QFETCH(int, round);
  QFETCH(int, pick);
  QFETCH(int, weeksOneWorthy);
  QFETCH(int, weeksTwoWorthy);
  QFETCH(int, gamesPlayed);
  QFETCH(double, value);
  QFETCH(int, posScarcity);

  PlayerData::Rank rank;
  rank.round = round;
  rank.pick = pick;

  PlayerData::Performance performance;
  performance.weeksOneWorthy = weeksOneWorthy;
  performance.weeksTwoWorthy = weeksTwoWorthy;
  performance.gamesPlayed = gamesPlayed;

  PlayerData data(date, rank, performance, value, posScarcity);

  QStringMap map = data.toQStringMap();

  QVERIFY(map[TIME_STAMP_KEY] == data.getDate().toString());
  QVERIFY(map[ROUND_KEY] == QString::number(data.getRank().round));
  QVERIFY(map[PICK_KEY] == QString::number(data.getRank().pick));
  QVERIFY(map[WEEKS_ONE_KEY] == QString::number(data.getPerformance().weeksOneWorthy));
  QVERIFY(map[WEEKS_TWO_KEY] == QString::number(data.getPerformance().weeksTwoWorthy));
  QVERIFY(map[VALUE_KEY] == QString::number(data.getValue()));
  QVERIFY(map[PS_KEY] == QString::number(data.getPositionalScarcity()));
}

void PlayerDataTests::checkToQStringMap_data() {
  QTest::addColumn<QDate>("date");
  QTest::addColumn<int>("round");
  QTest::addColumn<int>("pick");
  QTest::addColumn<int>("weeksOneWorthy");
  QTest::addColumn<int>("weeksTwoWorthy");
  QTest::addColumn<int>("gamesPlayed");
  QTest::addColumn<double>("value");
  QTest::addColumn<int>("posScarcity");

  QTest::addRow("Null Data")
      << QDate::currentDate() << 0 << 0 << 0 << 0 << 0 << 0. << 0;

  QTest::addRow("Star Player")
      << QDate(2017, 9, 1) << 1 << 1 << 18 << 0 << 18 << 8.6 << 99;

  QTest::addRow("Player (Null Date)")
      << QDate() << 0 << 0 << 0 << 0 << 0 << 0. << 0;

  QTest::addRow("Medoirce Player")
      << QDate::currentDate() << 5 << 12 << 3 << 15 << 18 << 4.5 << 50;
}

QTEST_MAIN(PlayerDataTests)
#include "player_data_tests.moc"
