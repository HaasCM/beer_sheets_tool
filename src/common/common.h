#ifndef COMMON_H
#define COMMON_H

#include <QtCore>

#ifndef NFL_TEAMS
#define NFL_TEAMS
#define PACKERS     QString("Green Bay Packers")
#define PATRIOTS    QString("New England Patriots")
#define SAINTS      QString("New Orleans Saints")
#define FALCONS     QString("Atlanta Falcons")
#define COLTS       QString("Indianappolis Colts")
#define SEAHAWKS    QString("Seattle Seahawks")
#define BUCCANEERS  QString("Tampa Bay Buccaneers")
#define TITANS      QString("Tennessee Titans")
#define REDSKINS    QString("Washington Redskins")
#define RAIDERS     QString("Oakland Raiders")
#define COWBOYS     QString("Dallas Cowboys")
#define PANTHERS    QString("Carolina Panthers")
#define STEELERS    QString("Pittsburgh Steelers")
#define LIONS       QString("Detroit Lions")
#define BENGALS     QString("Cincinatti Bengals")
#define DOLPHINS    QString("Miami Dolphins")
#define CHARGERS    QString("Los Angeles Chargers")
#define GIANTS      QString("New York Giants")
#define BILLS       QString("Buffalo Bills")
#define CHIEFS      QString("Kansas City Chiefs")
#define CARDINALS   QString("Arizona Cardinals")
#define JAGUARS     QString("Jacksonville Jaguars")
#define EAGLES      QString("Philadelphia Eagles")
#define RAVENS      QString("Baltimore Ravens")
#define VIKINGS     QString("Minnesota Vikings")
#define FORTYNINERS QString("San Fransico 49ers")
#define BEARS       QString("Chicago Bears")
#define BRONCOS     QString("Denver Broncos")
#define JETS        QString("New York Jets")
#define TEXANS      QString("Houston Texans")
#define BROWNS      QString("Cleveland Browns")
#define RAMS        QString("Los Angeles Rams")
#define FREE_AGENT  QString("Free Agent")
#endif

#ifndef POSITIONS
#define POSITIONS
#define QUARTERBACK   QString("Quarterback")
#define RUNNING_BACK  QString("Running Back")
#define WIDE_RECEIVER QString("Wide Receiver")
#define TIGHT_END     QString("Tight End")
#define DST           QString("Defense & Special Teams")
#define PLACE_KICKER  QString("Place Kicker")
#define FLEX          QString("Flex")
#endif

namespace Common {
  /*!
    \enum NFLTeam
    \brief Enum for NFL football team
  */

  enum class NFLTeam {
    Packers,
    Patriots,
    Saints,
    Falcons,
    Colts,
    Seahawks,
    Buccaneers,
    Titans,
    Redskins,
    Raiders,
    Cowboys,
    Panthers,
    Steelers,
    Lions,
    Bengals,
    Dolphins,
    Chargers,
    Giants,
    Bills,
    Chiefs,
    Cardinals,
    Jaguars,
    Eagles,
    Ravens,
    Vikings,
    FortyNiners,
    Bears,
    Broncos,
    Jets,
    Texans,
    Browns,
    Rams,
    FreeAgent,
  };

  static QString enumToString(const NFLTeam &team) {
    switch(team) {
      case NFLTeam::Packers:    return PACKERS;
      case NFLTeam::Patriots:   return PATRIOTS;
      case NFLTeam::Saints:     return SAINTS;
      case NFLTeam::Falcons:    return FALCONS;
      case NFLTeam::Colts:      return COLTS;
      case NFLTeam::Seahawks:   return SEAHAWKS;
      case NFLTeam::Buccaneers: return BUCCANEERS;
      case NFLTeam::Titans:     return TITANS;
      case NFLTeam::Redskins:   return REDSKINS;
      case NFLTeam::Raiders:    return RAIDERS;
      case NFLTeam::Cowboys:    return COWBOYS;
      case NFLTeam::Panthers:   return PANTHERS;
      case NFLTeam::Steelers:   return STEELERS;
      case NFLTeam::Lions:      return LIONS;
      case NFLTeam::Bengals:    return BENGALS;
      case NFLTeam::Dolphins:   return DOLPHINS;
      case NFLTeam::Chargers:   return CHARGERS;
      case NFLTeam::Giants:     return GIANTS;
      case NFLTeam::Bills:      return BILLS;
      case NFLTeam::Chiefs:     return CHIEFS;
      case NFLTeam::Cardinals:  return CARDINALS;
      case NFLTeam::Jaguars:    return JAGUARS;
      case NFLTeam::Eagles:     return EAGLES;
      case NFLTeam::Ravens:     return RAVENS;
      case NFLTeam::Vikings:    return VIKINGS;
      case NFLTeam::FortyNiners:return FORTYNINERS;
      case NFLTeam::Bears:      return BEARS;
      case NFLTeam::Broncos:    return BRONCOS;
      case NFLTeam::Jets:       return JETS;
      case NFLTeam::Texans:     return TEXANS;
      case NFLTeam::Browns:     return BROWNS;
      default:                  return FREE_AGENT;
    }
  }

  /*!
  \fn static T ::stringToEnum(const QString string)
  \brief template function to convert an enum to a string
*/
  template<typename E>
  E stringToEnum(const QString &string);

  /*!
  \fn static NFLTeam stringToEnum(const QString team)
  \brief takes a qstring and returns an nfl team enum
  */

  template<>
  NFLTeam stringToEnum<NFLTeam>(const QString &incomingTeam) {
    QString team = incomingTeam.toLower();
    if(team == PACKERS.toLower()          || team == "gb"){                  return NFLTeam::Packers;}
    else if(team == PATRIOTS.toLower()    || team == "ne"){                  return NFLTeam::Patriots;}
    else if(team == SAINTS.toLower()      || team == "no"){                  return NFLTeam::Saints;}
    else if(team == FALCONS.toLower()     || team == "atl"){                 return NFLTeam::Falcons;}
    else if(team == COLTS.toLower()       || team == "ind"){                 return NFLTeam::Colts;}
    else if(team == SEAHAWKS.toLower()    || team == "sea"){                 return NFLTeam::Seahawks;}
    else if(team == BUCCANEERS.toLower()  || team == "tb"){                  return NFLTeam::Buccaneers;}
    else if(team == TITANS.toLower()      || team == "ten"){                 return NFLTeam::Titans;}
    else if(team == REDSKINS.toLower()    || team == "was"){                 return NFLTeam::Redskins;}
    else if(team == RAIDERS.toLower()     || team == "oak"){                 return NFLTeam::Raiders;}
    else if(team == COWBOYS.toLower()     || team == "dal"){                 return NFLTeam::Cowboys;}
    else if(team == PANTHERS.toLower()    || team == "car"){                 return NFLTeam::Panthers;}
    else if(team == STEELERS.toLower()    || team == "pit"){                 return NFLTeam::Steelers;}
    else if(team == LIONS.toLower()       || team == "det"){                 return NFLTeam::Lions;}
    else if(team == BENGALS.toLower()     || team == "cin"){                 return NFLTeam::Bengals;}
    else if(team == DOLPHINS.toLower()    || team == "mia"){                 return NFLTeam::Dolphins;}
    else if(team == GIANTS.toLower()      || team == "nyg"){                 return NFLTeam::Giants;}
    else if(team == BILLS.toLower()       || team == "buf"){                 return NFLTeam::Bills;}
    else if(team == CHIEFS.toLower()      || team == "kc"){                  return NFLTeam::Chiefs;}
    else if(team == CARDINALS.toLower()   || team == "ari"){                 return NFLTeam::Cardinals;}
    else if(team == JAGUARS.toLower()     || team == "jax"){                 return NFLTeam::Jaguars;}
    else if(team == EAGLES.toLower()      || team == "phi"){                 return NFLTeam::Eagles;}
    else if(team == RAVENS.toLower()      || team == "bal"){                 return NFLTeam::Ravens;}
    else if(team == VIKINGS.toLower()     || team == "min"){                 return NFLTeam::Vikings;}
    else if(team == FORTYNINERS.toLower() || team == "sf"){                  return NFLTeam::FortyNiners;}
    else if(team == BEARS.toLower()       || team == "chi"){                 return NFLTeam::Bears;}
    else if(team == BRONCOS.toLower()     || team == "den"){                 return NFLTeam::Broncos;}
    else if(team == JETS.toLower()        || team == "nyj"){                 return NFLTeam::Jets;}
    else if(team == TEXANS.toLower()      || team == "hou"){                 return NFLTeam::Texans;}
    else if(team == BROWNS.toLower()      || team == "cle"){                 return NFLTeam::Browns;}
    else if(team == RAMS.toLower()        || team == "lar" || team == "la"){ return NFLTeam::Rams;}
    else if(team == CHARGERS.toLower()    || team == "lac" || team == "sd"){ return NFLTeam::Chargers;}
    else return NFLTeam::FreeAgent;
  }

  /*!
    \enum Position
    \brief Enum to depict NFL Position
  */

  enum class Position {
    Quarterback,
    RunningBack,
    WideReceiver,
    TightEnd,
    PlaceKicker,
    DefenseSpecialTeams,
    Flex
  };

  /*!
    \fn QString enumToString(const Position &pos)
    \brief Takes in a position enum and return a QString
  */

  QString enumToString(const Position &pos) {
    switch(pos) {
      case Position::Quarterback:
        return QUARTERBACK;
      case Position::RunningBack:
        return RUNNING_BACK;
      case Position::WideReceiver:
        return WIDE_RECEIVER;
      case Position::TightEnd:
        return TIGHT_END;
      case Position::PlaceKicker:
        return PLACE_KICKER;
      case Position::DefenseSpecialTeams:
        return DST;
      default:
        return FLEX;
    }
  }

  /*!
  \fn Position stringToEnum(const QString &incomingPos)
  \brief takes in a QSTring and  returns the position enum
*/

  template<>
  Position stringToEnum<Position>(const QString &incomingPos) {
    QString pos = incomingPos.toLower();
    if(pos == QUARTERBACK.toLower()){       return Position::Quarterback;}
    else if(pos == RUNNING_BACK.toLower()){ return Position::RunningBack;}
    else if(pos == WIDE_RECEIVER.toLower()){return Position::WideReceiver;}
    else if(pos == TIGHT_END.toLower()){    return Position::TightEnd;}
    else if(pos == PLACE_KICKER.toLower()){ return Position::PlaceKicker;}
    else if(pos == DST.toLower()){          return Position::DefenseSpecialTeams;}
    else {                                  return Position::Flex;}
  }
}

#endif // COMMON_H
