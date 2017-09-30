/*!
  \file sheet_rules_tests.cpp
  \brief file to define and implement the sheet rules unit tests
*/

#include "sheet_rules.h"
#include<QtTest/QtTest>

class SheetRulesTests : public QObject {
  Q_OBJECT
private slots:
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

  QTest::addRow("Standard") << 0;

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

  QTest::addRow("Snake") << SheetType::Snake;

  QTest::addRow("Custom") << SheetType::Custom;
}

void SheetRulesTests::checkScoringRules() {

}

void SheetRulesTests::checkScoringRules_data() {

}

void SheetRulesTests::checkPlayerLimits() {

}

void SheetRulesTests::checkPlayerLimits_data() {

}

void SheetRulesTests::checkEquality() {

}

void SheetRulesTests::checkEquality_data() {

}

void SheetRulesTests::checkInequality() {

}

void SheetRulesTests::checkInequality_data() {

}

void SheetRulesTests::checkStringToSheetType() {

}

void SheetRulesTests::checkStringToSheetType_data() {

}

void SheetRulesTests::checkSheetTypeToString() {

}

void SheetRulesTests::checkSheetTypeToString_data() {

}

QTEST_MAIN(SheetRulesTests)
#include "sheet_rules_tests.moc"
