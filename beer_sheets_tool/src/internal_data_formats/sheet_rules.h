/*!
  \file sheet_rules.h
  \brief definition of the SheetRules class
*/

#ifndef SHEET_RULES_H
#define SHEET_RULES_H

#include <QString>

/*!
  \enum SheetType
  \brief enum to idenitfy beersheet type
*/

enum class SheetType {
  Snake,
  Auction,
  Custom
};

typedef struct {
  int pointsPerTD = 6;
  double pointsPerYard = 0.04;
} ScoringRules;

typedef struct {
  int quarterbacks = 0;
  int runningBacks = 0;
  int wideReceivers = 0;
  int tightEnds = 0;
  int flexes = 0;
  int DST = 0;
  int PK = 0;
} PlayerLimits;

/*!
  \enum RuleType
  \brief enum to handle the rule type
*/
enum class RuleType {
  Passing,
  Rushing,
  Receiving,
};

/*!
  \class SheetRules
  \brief Class to hold attributes and behaviors for BeerSheet league rules
*/
class SheetRules {
public:
  SheetRules(SheetType type);


  double getPPR() const;
  SheetType getSheetType() const;
  ScoringRules getScoringRules(const RuleType type) const;
  PlayerLimits getLimits() const;
  int getTeamSize() const;

  void setScoringRules(const ScoringRules &rules, const RuleType type);
  void setLimits(const PlayerLimits &limits);
  void setTeamSize(const int size);
  void setPPR(const double ppr);

  bool operator==(const SheetRules &other) const;
  bool operator!=(const SheetRules &other) const;

  static SheetType stringToSheetType(QString string);
  static QString sheetTypeToString(SheetType type);

private:
  int mTeamSize = 0; //!< number of players per team
  double mPPR = 0; //!< points per reception

  SheetType mSheetType; //!< The sheettype for the associated beersheet
  ScoringRules mPassingRules; //!< passing rules for the beersheet
  ScoringRules mRushingRules; //!< rushing rules for the beersheet
  ScoringRules mReceivingRules; //!< receiving rules for the beersheet
  PlayerLimits mTeamLimits; //!< limits per team
};

#endif // SHEET_RULES_H
