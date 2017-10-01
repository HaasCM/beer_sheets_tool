/*!
  \file sheet_rules.h
  \brief definition of the SheetRules class
*/

#ifndef SHEET_RULES_H
#define SHEET_RULES_H


#include <QString>
#include <QMetaType>

/*!
  \enum SheetType
  \brief enum to idenitfy beersheet type
*/

enum class SheetType {
  Snake,
  Auction,
  Custom
};
Q_DECLARE_METATYPE(SheetType);

struct ScoringRules {
public:
  int pointsPerTD;
  double pointsPerYard;

  ScoringRules(int ppTD = 6, double ppY = 0.04) : pointsPerTD(ppTD), pointsPerYard(ppY) {}
};
typedef struct ScoringRules ScoringRules;
Q_DECLARE_METATYPE(ScoringRules);

struct PlayerLimits {
public:
  int quarterbacks;
  int runningBacks;
  int wideReceivers;
  int tightEnds;
  int flexes;
  int DST;
  int PK;

  PlayerLimits(int qb = 0, int rb = 0, int wr = 0, int te = 0, int flex = 0, int dst = 0, int pk = 0) :
  quarterbacks(qb), runningBacks(rb), wideReceivers(wr), tightEnds(te), flexes(flex), DST(dst), PK(pk) {}
};
typedef struct PlayerLimits PlayerLimits;
Q_DECLARE_METATYPE(PlayerLimits);

/*!
  \enum RuleType
  \brief enum to handle the rule type
*/
enum class RuleType {
  Passing,
  Rushing,
  Receiving,
};
Q_DECLARE_METATYPE(RuleType);

/*!
  \class SheetRules
  \brief Class to hold attributes and behaviors for BeerSheet league rules
*/
class SheetRules {
public:
  SheetRules(SheetType type);

  static const QString SnakeEnumQString;
  static const QString AuctionEnumQString;
  static const QString CustomEnumQString;

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
