/*!
  \file beersheet.h
  \brief file to define BeerSheet
*/

#ifndef BEERSHEET_H
#define BEERSHEET_H

#include "player.h"
#include "common.h"

#include <QtCore>

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
  int quarterBacks = 0;
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
  Recieving,
};


/*!
  \class BeerSheet
  \brief class to contain info for one beersheet
*/

class BeerSheet : public QObject{
  Q_OBJECT

public:
  typedef QMap<Common::Position, QList<Player>> Players;

  BeerSheet(SheetType type=SheetType::Snake, QObject *parent=nullptr);
  ~BeerSheet();

  SheetType getSheetType() const;
  ScoringRules getRules(const RuleType type) const;
  PlayerLimits getLimits() const;
  QDate getDate() const;

  void setRules(const ScoringRules &rules, const RuleType type);
  void setLimits(const PlayerLimits &limits);
  void setTeamSize(const int size);
  void setPPR(const double ppr);
  void setDate(const QDate &date);

  void addPlayer(Player player);

  static SheetType stringToSheetType(QString string);

protected:

private:
  SheetType mSheetType; //!< BeerSheet Type
  int mTeamSize = 0; //!< number of players per team
  double mPPR = 0; //!< points per reception
  QDate mDate; //!< the QDate that this sheet was updated

  ScoringRules mPassingRules; //!< passing rules for the beersheet
  ScoringRules mRushingRules; //!< rushing rules for the beersheet
  ScoringRules mReceivingRules; //!< receiving rules for the beersheet
  PlayerLimits mTeamLimits; //!< limits per team

  Players mPlayers;

};

#endif //BEERSHEET_H
