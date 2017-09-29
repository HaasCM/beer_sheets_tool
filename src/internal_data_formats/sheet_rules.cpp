/*!
  \file sheet_rules.cpp
  \brief Implementation of the SheetRules class
*/

#include "sheet_rules.h"

#include <QtCore>

SheetRules::SheetRules(SheetType type) :
  mSheetType(type) {

}

/*!
  \brief returns the pointer per reception
  \return points per reception
*/
double SheetRules::getPPR() const {
  return mPPR;
}

/*!
  \brief returns the sheet type
  \return The type of draft this sheet covers
*/
SheetType SheetRules::getSheetType() const {
  return mSheetType;
}

/*!
  \brief Returns the scoring rules for the Rule Type
  \param type the specific rules requested
  \return the associated scoring rules for type
*/
ScoringRules SheetRules::getScoringRules(const RuleType type) const {
  switch(type) {
    case RuleType::Passing: {
      return mPassingRules;
    }

    case RuleType::Recieving: {
      return mReceivingRules;
    }

    case RuleType::Rushing: {
      return mRushingRules;
    }
  }
}

/*!
  \brief Returns the player limit struct for teams
  \return the player limit struct for this sheet
*/
PlayerLimits SheetRules::getLimits() const {
  return mTeamLimits;
}

/*!
  \brief Sets the rules for the specified type
  \param rules the rules to set
  \param type the type of rules to set
*/
void SheetRules::setScoringRules(const ScoringRules &rules, const RuleType type) {
  switch(type) {
    case RuleType::Passing: {
      mPassingRules = rules;
      break;
    }

    case RuleType::Recieving: {
      mReceivingRules = rules;
      break;
    }

    case RuleType::Rushing: {
      mRushingRules = rules;
      break;
    }
  }
}

/*!
  \brief Sets team limits for this rule set
  \param limits the struct for the team limits
*/
void SheetRules::setLimits(const PlayerLimits &limits) {
  mTeamLimits = limits;
}

/*!
  \brief Sets the amount of teams in the league
  \param size the amount of teams in the league
*/
void SheetRules::setTeamSize(const int size) {
  mTeamSize = size;
}

/*!
  \brief Sets the PPR scoring for this league
  \param ppr the ppr scoring
*/
void SheetRules::setPPR(const double ppr) {
  mPPR = ppr;
}

/*!
  \brief comparator operator for rule sets
  \param other the other set of rules to compare against
  \return returns true if equal, otherwise false.
*/
bool SheetRules::operator==(const SheetRules &other) const {
  auto compareScoringRules = [&](const ScoringRules &lhs, const ScoringRules &rhs) {
    return(lhs.pointsPerTD == rhs.pointsPerTD &&
           qFuzzyCompare(lhs.pointsPerYard, rhs.pointsPerYard));
  };

  auto comparePlayerLimits = [&](const PlayerLimits &lhs, const PlayerLimits &rhs) {
    return(lhs.quarterbacks   == rhs.quarterbacks  &&
           lhs.runningBacks   == rhs.runningBacks  &&
           lhs.wideReceivers  == rhs.wideReceivers &&
           lhs.tightEnds      == rhs.tightEnds     &&
           lhs.flexes         == rhs.flexes        &&
           lhs.DST            == rhs.DST           &&
           lhs.PK             == rhs.PK);
  };

  return(this->mTeamSize  == other.mTeamSize                         &&
         this->mSheetType == other.mSheetType                        &&
         qFuzzyCompare(this->mPPR, other.mPPR)                       &&
         compareScoringRules(mPassingRules, other.mPassingRules)     &&
         compareScoringRules(mReceivingRules, other.mReceivingRules) &&
         compareScoringRules(mRushingRules, other.mRushingRules)     &&
         comparePlayerLimits(mTeamLimits, other.mTeamLimits));
}

/*!
  \brief inverse comparator operator for rules
  \param other the other set of rules to compare against
  \return true if not equal, otherwise false
*/
bool SheetRules::operator!=(const SheetRules &other) const {
  return(!((*this)==other));
}
