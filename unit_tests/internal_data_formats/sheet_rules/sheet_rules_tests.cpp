/*!
  \file sheet_rules_tests.cpp
  \brief file to define and implement the sheet rules unit tests
*/

#include "sheet_rules.h"
#include<QtTest/QtTest>

class SheetRulesTests : public QObject {
  Q_OBJECT
private slots:
  void setUp();

  void checkPPR();
  void checkPPR_data();

  void checkSheetType();
  void checkSheetType_data();

  void checkScoringRules();
  void checkScoringRules_data();

  void checkPlayerLimits();
  void checkPlayerLimits_data();

  void checkEquality();
  void checkEquality_data();

  void checkInequality();
  void checkInequality_data();

  void checkStringToSheetType();
  void checkStringToSheetType_data();

  void checkSheetTypeToString();
  void checkSheetTypeToString_data();
};

void SheetRulesTests::setUp() {
  qRegisterMetaType<SheetType>("SheetType");
  qRegisterMetaType<ScoringRules>("ScoringRules");
  qRegisterMetaType<PlayerLimits>("PlayerLimits");
  qRegisterMetaType<RuleType>("RuleType");
}

/*!
  \brief Function to test the ppr interface
*/
void SheetRulesTests::checkPPR() {
  QFETCH(double, ppr);

  SheetRules rules(SheetType::Snake);

  rules.setPPR(ppr);

  QVERIFY(qFuzzyCompare(rules.getPPR(), ppr));

  ppr += 1.0;

  QVERIFY(!(qFuzzyCompare(rules.getPPR(), ppr)));
}

/*!
  \brief Function to generate the data for the PPR interface tests
*/
void SheetRulesTests::checkPPR_data() {
  QTest::addColumn<double>("ppr");

  QTest::addRow("Standard")   << 0.0;

  QTest::addRow("Half Point") << 0.5;

  QTest::addRow("Full Point") << 1.0;
}

/*!
  \brief Function to test the sheet type interface
*/
void SheetRulesTests::checkSheetType() {
  QFETCH(SheetType, type);

  SheetRules rules(type);

  QVERIFY(rules.getSheetType() == type);
}

/*!
  \brief Function to generate the data for the SheetType interface tests
*/
void SheetRulesTests::checkSheetType_data() {
  QTest::addColumn<SheetType>("type");

  QTest::addRow("Auction") << SheetType::Auction;

  QTest::addRow("Snake")   << SheetType::Snake;

  QTest::addRow("Custom")  << SheetType::Custom;
}

/*!
  \brief Function to test the ScoringRules public interface
*/
void SheetRulesTests::checkScoringRules() {
  QFETCH(ScoringRules, passingRules);
  QFETCH(ScoringRules, rushingRules);
  QFETCH(ScoringRules, receivingRules);


  SheetRules rules(SheetType::Snake);

  rules.setScoringRules(passingRules,   RuleType::Passing);
  rules.setScoringRules(rushingRules,   RuleType::Rushing);
  rules.setScoringRules(receivingRules, RuleType::Receiving);

  auto verifyRules = [&](ScoringRules expected, ScoringRules actual) {
    QVERIFY(expected.pointsPerTD == actual.pointsPerTD);
    QVERIFY(qFuzzyCompare(expected.pointsPerYard, actual.pointsPerYard));
  };

  verifyRules(passingRules,   rules.getScoringRules(RuleType::Passing));
  verifyRules(rushingRules,   rules.getScoringRules(RuleType::Rushing));
  verifyRules(receivingRules, rules.getScoringRules(RuleType::Receiving));
}

/*!
  \brief Function to generate the test matrix for the ScoringRules unit tests
*/
void SheetRulesTests::checkScoringRules_data() {
  QTest::addColumn<ScoringRules>("passingRules");
  QTest::addColumn<ScoringRules>("rushingRules");
  QTest::addColumn<ScoringRules>("receivingRules");

  QTest::addRow("Standard Rules")
      << ScoringRules(4, 0.04)  << ScoringRules(6, 0.04)  << ScoringRules(6, 0.04);

  QTest::addRow("Zeroed Rules")
      << ScoringRules(0, 0)     << ScoringRules(0, 0)     << ScoringRules(0, 0);

  QTest::addRow("Uninitialized Rules")
      << ScoringRules()         << ScoringRules()         << ScoringRules();
}

/*!
  \brief Function to check the PlayerLimits public interface
*/
void SheetRulesTests::checkPlayerLimits() {
  QFETCH(PlayerLimits, playerLimits);

  SheetRules rules(SheetType::Snake);

  rules.setLimits(playerLimits);

  QVERIFY(rules.getLimits().quarterbacks  == playerLimits.quarterbacks);
  QVERIFY(rules.getLimits().runningBacks  == playerLimits.runningBacks);
  QVERIFY(rules.getLimits().wideReceivers == playerLimits.wideReceivers);
  QVERIFY(rules.getLimits().tightEnds     == playerLimits.tightEnds);
  QVERIFY(rules.getLimits().flexes        == playerLimits.flexes);
  QVERIFY(rules.getLimits().DST           == playerLimits.DST);
  QVERIFY(rules.getLimits().PK            == playerLimits.PK);
}

/*!
  \brief Functon to generate the data for the PlayerLimits Tests
*/
void SheetRulesTests::checkPlayerLimits_data() {
  QTest::addColumn<PlayerLimits>("playerLimits");

  QTest::addRow("Uninitialized Limits") << PlayerLimits();

  QTest::addRow("1QB, 2RB, 2WR, 1TE, 1DST, 1PK") << PlayerLimits(1, 2, 2, 1, 1, 1);

  QTest::addRow("2QB, 2RB, 2WR, 1TE, 1DST, 1PK") << PlayerLimits(2, 2, 2, 1, 1, 1);

  QTest::addRow("1QB, 3RB, 2WR, 1TE, 1DST, 1PK") << PlayerLimits(1, 3, 2, 1, 1, 1);

  QTest::addRow("1QB, 2RB, 3WR, 1TE, 1DST, 1PK") << PlayerLimits(1, 2, 3, 1, 1, 1);

  QTest::addRow("2QB, 3RB, 3WR, 1TE, 1DST, 1PK") << PlayerLimits(2, 3, 3, 1, 1, 1);
}

void SheetRulesTests::checkEquality() {
  QFETCH(SheetType, sheetType);
  QFETCH(int, teamSize);
  QFETCH(double, ppr);
  QFETCH(ScoringRules, passingRules);
  QFETCH(ScoringRules, rushingRules);
  QFETCH(ScoringRules, receivingRules);
  QFETCH(PlayerLimits, teamLimits);

  SheetRules expected(sheetType);

  expected.setTeamSize(teamSize);
  expected.setPPR(ppr);

  expected.setScoringRules(passingRules, RuleType::Passing);
  expected.setScoringRules(rushingRules, RuleType::Rushing);
  expected.setScoringRules(receivingRules, RuleType::Receiving);

  expected.setLimits(teamLimits);

  SheetRules actual(sheetType);

  actual.setTeamSize(teamSize);
  actual.setPPR(ppr);

  actual.setScoringRules(passingRules, RuleType::Passing);
  actual.setScoringRules(rushingRules, RuleType::Rushing);
  actual.setScoringRules(receivingRules, RuleType::Receiving);

  actual.setLimits(teamLimits);

  QVERIFY(expected == actual);

  actual.setPPR((expected.getPPR() + 1.0));
  QVERIFY(!(expected == actual));
  actual.setPPR((expected.getPPR()));

  actual.setTeamSize((expected.getTeamSize() + 1));
  QVERIFY(!(expected == actual));
  actual.setTeamSize((expected.getTeamSize()));

  //TODO evaulate if more rigor is needed here

}

void SheetRulesTests::checkEquality_data() {
  QTest::addColumn<SheetType>("sheetType");
  QTest::addColumn<int>("teamSize");
  QTest::addColumn<double>("ppr");
  QTest::addColumn<ScoringRules>("passingRules");
  QTest::addColumn<ScoringRules>("rushingRules");
  QTest::addColumn<ScoringRules>("receivingRules");
  QTest::addColumn<PlayerLimits>("teamLimits");

  QTest::addRow("Unitialized")        << SheetType::Snake << 0 << 0.
                                      << ScoringRules() << ScoringRules()
                                      << ScoringRules() << PlayerLimits();

  QTest::addRow("Snake-12-Standard")  << SheetType::Snake << 12 << 0.
                                      << ScoringRules(4, 0.04) << ScoringRules(6, 0.1)
                                      << ScoringRules(6, 0.1) << PlayerLimits(1, 2, 2, 1, 1, 1);

  QTest::addRow("Custom-10-1PPR")     << SheetType::Custom << 10 << 1.0
                                      << ScoringRules(4, 0.04) << ScoringRules(6, 0.1)
                                      << ScoringRules(6, 0.1) << PlayerLimits(1, 2, 2, 1, 1, 1);

  QTest::addRow("Auction-8-0.5PPR")   << SheetType::Auction << 8 << 0.5
                                      << ScoringRules(4, 0.04) << ScoringRules(6, 0.1)
                                      << ScoringRules(6, 0.1) << PlayerLimits(1, 2, 2, 1, 1, 1);
}

void SheetRulesTests::checkInequality() {
  QFETCH(SheetType, sheetType);
  QFETCH(int, teamSize);
  QFETCH(double, ppr);
  QFETCH(ScoringRules, passingRules);
  QFETCH(ScoringRules, rushingRules);
  QFETCH(ScoringRules, receivingRules);
  QFETCH(PlayerLimits, teamLimits);

  SheetRules expected(sheetType);

  expected.setTeamSize(teamSize);
  expected.setPPR(ppr);

  expected.setScoringRules(passingRules, RuleType::Passing);
  expected.setScoringRules(rushingRules, RuleType::Rushing);
  expected.setScoringRules(receivingRules, RuleType::Receiving);

  expected.setLimits(teamLimits);

  SheetRules actual(sheetType);

  actual.setTeamSize((teamSize + 1));
  actual.setPPR((ppr + 1));

  auto changeRules = [&](ScoringRules rule, RuleType type) {
    rule.pointsPerTD += 1;
    rule.pointsPerYard += 1;

    actual.setScoringRules(rule, type);
  };

  changeRules(passingRules, RuleType::Passing);
  changeRules(rushingRules, RuleType::Rushing);
  changeRules(receivingRules, RuleType::Receiving);

  actual.setLimits(teamLimits);

  QVERIFY(expected != actual);
}

void SheetRulesTests::checkInequality_data() {
  QTest::addColumn<SheetType>("sheetType");
  QTest::addColumn<int>("teamSize");
  QTest::addColumn<double>("ppr");
  QTest::addColumn<ScoringRules>("passingRules");
  QTest::addColumn<ScoringRules>("rushingRules");
  QTest::addColumn<ScoringRules>("receivingRules");
  QTest::addColumn<PlayerLimits>("teamLimits");

  QTest::addRow("Unitialized")        << SheetType::Snake << 0 << 0.
                                      << ScoringRules() << ScoringRules()
                                      << ScoringRules() << PlayerLimits();

  QTest::addRow("Snake-12-Standard")  << SheetType::Snake << 12 << 0.
                                      << ScoringRules(4, 0.04) << ScoringRules(6, 0.1)
                                      << ScoringRules(6, 0.1) << PlayerLimits(1, 2, 2, 1, 1, 1);

  QTest::addRow("Custom-10-1PPR")     << SheetType::Custom << 10 << 1.0
                                      << ScoringRules(4, 0.04) << ScoringRules(6, 0.1)
                                      << ScoringRules(6, 0.1) << PlayerLimits(1, 2, 2, 1, 1, 1);

  QTest::addRow("Auction-8-0.5PPR")   << SheetType::Auction << 8 << 0.5
                                      << ScoringRules(4, 0.04) << ScoringRules(6, 0.1)
                                      << ScoringRules(6, 0.1) << PlayerLimits(1, 2, 2, 1, 1, 1);
}

void SheetRulesTests::checkStringToSheetType() {
  QFETCH(QString, stringToConvert);
  QFETCH(SheetType, expectedType);

  QVERIFY(SheetRules::stringToSheetType(stringToConvert) == expectedType);
}

void SheetRulesTests::checkStringToSheetType_data() {
  QTest::addColumn<QString>("stringToConvert");
  QTest::addColumn<SheetType>("expectedType");

  QTest::addRow("snake")            << "snake"            << SheetType::Snake;

  QTest::addRow("SNAKE")            << "SNAKE"            << SheetType::Snake;

  QTest::addRow("SnAkE")            << "SnAkE"            << SheetType::Snake;

  QTest::addRow("Snake")            << "Snake"            << SheetType::Snake;

  QTest::addRow("auction")          << "auction"          << SheetType::Auction;

  QTest::addRow("AUCTION")          << "AUCTION"          << SheetType::Auction;

  QTest::addRow("AucTiOn")          << "AucTiOn"          << SheetType::Auction;

  QTest::addRow("Auction")          << "Auction"          << SheetType::Auction;

  QTest::addRow("custom")           << "custom"           << SheetType::Custom;

  QTest::addRow("")                 << ""                 << SheetType::Custom;

  QTest::addRow("NULL")             << "NULL"             << SheetType::Custom;

  QTest::addRow("CuStomIzed TexT")  << "CuStomIzed TexT"  << SheetType::Custom;
}

void SheetRulesTests::checkSheetTypeToString() {

}

void SheetRulesTests::checkSheetTypeToString_data() {
  QTest::addColumn<SheetType>("typeToConvert");
  QTest::addColumn<QString>("expectedString");

  QTest::addRow("Snake")    << SheetType::Snake   << SheetRules::SnakeEnumQString;

  QTest::addRow("Auction")  << SheetType::Auction << SheetRules::AuctionEnumQString;

  QTest::addRow("Custom")   << SheetType::Custom  << SheetRules::CustomEnumQString;
}

QTEST_MAIN(SheetRulesTests)
#include "sheet_rules_tests.moc"
