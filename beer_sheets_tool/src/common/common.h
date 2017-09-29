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
#define QUARTERBACK          QString("Quarterback")
#define RUNNING_BACK         QString("Running Back")
#define WIDE_RECEIVER        QString("Wide Receiver")
#define TIGHT_END            QString("Tight End")
#define DEFENSE_ST           QString("Defense & Special Teams")
#define PLACE_KICKER         QString("Place Kicker")
#define FLEX                 QString("Flex")
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

  class NFLEnumHandler {
    public:
      /*!
         \fn NFLEnumHandler& NFLEnumHandler::instance()
         \brief returns an instance of the NFL enumhandler
       */
      static NFLEnumHandler& instance() {
        static NFLEnumHandler instance;
        return instance;
      }
      NFLEnumHandler(NFLEnumHandler const&) = delete;
      void operator=(NFLEnumHandler const&) = delete;

      /*!
        \fn Position NFLEnumHandler::translatePosition(const QString pos) const
        \brief returns the position as an enum
      */
      Common::Position translatePosition(const QString pos) const {
        return mPositionsEnums.value(pos);
      }

      /*!
        \brief converts the position from an enum to a string
        \param pos position to convert
        \return a qstring representing the position
       */
      QString translatePosition(const Common::Position &pos) const {
        // Not really efficient, but its simple and for the size of the map
        // it should be sufficient
        //WARNING This is a bad key lookup
        return mPositionsEnums.key(pos);
      }

      /*!
        \fn Common::NFLTeam translateTeam(const QString team) const
        \brief brief
      */
      Common::NFLTeam translateTeam(const QString team) const {
        return mNFLTeamEnums.value(team);
      }

      QString translateTeam(const Common::NFLTeam &team) const {
        return mNFLTeamEnums.key(team);
      }

    private:
      NFLEnumHandler() {
        // populate the positions map
        mPositionsEnums[QUARTERBACK] = Position::Quarterback;
        mPositionsEnums[RUNNING_BACK] = Position::RunningBack;
        mPositionsEnums[WIDE_RECEIVER] = Position::WideReceiver;
        mPositionsEnums[TIGHT_END] = Position::TightEnd;
        mPositionsEnums[DEFENSE_ST] = Position::DefenseSpecialTeams;
        mPositionsEnums[FLEX] = Position::Flex;
        mPositionsEnums[PLACE_KICKER] = Position::PlaceKicker;

        //populate the teams map
        mNFLTeamEnums[PACKERS] = NFLTeam::Packers;
        mNFLTeamEnums[PATRIOTS] = NFLTeam::Patriots;
        mNFLTeamEnums[SAINTS] = NFLTeam::Saints;
        mNFLTeamEnums[FALCONS] = NFLTeam::Falcons;
        mNFLTeamEnums[COLTS] = NFLTeam::Colts;
        mNFLTeamEnums[SEAHAWKS] = NFLTeam::Seahawks;
        mNFLTeamEnums[BUCCANEERS] = NFLTeam::Buccaneers;
        mNFLTeamEnums[TITANS] = NFLTeam::Titans;
        mNFLTeamEnums[REDSKINS] = NFLTeam::Redskins;
        mNFLTeamEnums[RAIDERS] = NFLTeam::Raiders;
        mNFLTeamEnums[COWBOYS] = NFLTeam::Cowboys;
        mNFLTeamEnums[PANTHERS] = NFLTeam::Panthers;
        mNFLTeamEnums[STEELERS] = NFLTeam::Steelers;
        mNFLTeamEnums[LIONS] = NFLTeam::Lions;
        mNFLTeamEnums[BENGALS] = NFLTeam::Bengals;
        mNFLTeamEnums[DOLPHINS] = NFLTeam::Dolphins;
        mNFLTeamEnums[CHARGERS] = NFLTeam::Chargers;
        mNFLTeamEnums[GIANTS] = NFLTeam::Giants;
        mNFLTeamEnums[BILLS] = NFLTeam::Bills;
        mNFLTeamEnums[CHIEFS] = NFLTeam::Chiefs;
        mNFLTeamEnums[CARDINALS] = NFLTeam::Cardinals;
        mNFLTeamEnums[JAGUARS] = NFLTeam::Jaguars;
        mNFLTeamEnums[EAGLES] = NFLTeam::Eagles;
        mNFLTeamEnums[RAVENS] = NFLTeam::Ravens;
        mNFLTeamEnums[VIKINGS] = NFLTeam::Vikings;
        mNFLTeamEnums[FORTYNINERS] = NFLTeam::FortyNiners;
        mNFLTeamEnums[BEARS] = NFLTeam::Bears;
        mNFLTeamEnums[BRONCOS] = NFLTeam::Broncos;
        mNFLTeamEnums[JETS] = NFLTeam::Jets;
        mNFLTeamEnums[TEXANS] = NFLTeam::Texans;
        mNFLTeamEnums[BROWNS] = NFLTeam::Browns;
        mNFLTeamEnums[RAMS] = NFLTeam::Rams;
        mNFLTeamEnums[FREE_AGENT] = NFLTeam::FreeAgent;
        mNFLTeamEnums["GB"] = NFLTeam::Packers;
        mNFLTeamEnums["NE"] = NFLTeam::Patriots;
        mNFLTeamEnums["NO"] = NFLTeam::Saints;
        mNFLTeamEnums["ATL"] = NFLTeam::Falcons;
        mNFLTeamEnums["IND"] = NFLTeam::Colts;
        mNFLTeamEnums["SEA"] = NFLTeam::Seahawks;
        mNFLTeamEnums["TB"] = NFLTeam::Buccaneers;
        mNFLTeamEnums["TEN"] = NFLTeam::Titans;
        mNFLTeamEnums["WAS"] = NFLTeam::Redskins;
        mNFLTeamEnums["DAL"] = NFLTeam::Cowboys;
        mNFLTeamEnums["CAR"] = NFLTeam::Panthers;
        mNFLTeamEnums["PIT"] = NFLTeam::Steelers;
        mNFLTeamEnums["DET"] = NFLTeam::Lions;
        mNFLTeamEnums["CIN"] = NFLTeam::Bengals;
        mNFLTeamEnums["MIA"] = NFLTeam::Dolphins;
        mNFLTeamEnums["SD"] = NFLTeam::Chargers;
        mNFLTeamEnums["LAC"] = NFLTeam::Chargers;
        mNFLTeamEnums["NYG"] = NFLTeam::Giants;
        mNFLTeamEnums["BUF"] = NFLTeam::Bills;
        mNFLTeamEnums["KC"] = NFLTeam::Chiefs;
        mNFLTeamEnums["ARI"] = NFLTeam::Cardinals;
        mNFLTeamEnums["JAX"] = NFLTeam::Jaguars;
        mNFLTeamEnums["PHI"] = NFLTeam::Eagles;
        mNFLTeamEnums["BAL"] = NFLTeam::Ravens;
        mNFLTeamEnums["MIN"] = NFLTeam::Vikings;
        mNFLTeamEnums["SF"] = NFLTeam::FortyNiners;
        mNFLTeamEnums["CHI"] = NFLTeam::Bears;
        mNFLTeamEnums["DEN"] = NFLTeam::Broncos;
        mNFLTeamEnums["NYJ"] = NFLTeam::Jets;
        mNFLTeamEnums["HOU"] = NFLTeam::Texans;
        mNFLTeamEnums["LAR"] = NFLTeam::Raiders;
        mNFLTeamEnums["SL"] = NFLTeam::Rams;
        mNFLTeamEnums["FA"] = NFLTeam::FreeAgent;
        mNFLTeamEnums[""] = NFLTeam::FreeAgent;

      }
      QMap <QString, Common::Position> mPositionsEnums;
      QMap <QString, Common::NFLTeam> mNFLTeamEnums; // just dealing with the linear time for the reverse lookup, N is not too large
};

}

#endif // COMMON_H
