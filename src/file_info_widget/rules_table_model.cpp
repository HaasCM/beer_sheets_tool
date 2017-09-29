#include "rules_table_model.h"

RulesTableModel::RulesTableModel(QObject *parent)
  : QAbstractTableModel(parent) {
}

QVariant RulesTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if(role == Qt::DisplayRole) {
    if(orientation == Qt::Horizontal) {
      switch(section) {
        case 0: {
          return QString("Draft Type");
        } case 1: {
          return QString("League Size");
        } case 2: {
          return QString("Points Per Reception");
        } case 3: {
          return QString("Player Limits");
        } default: {
          return QString("Unhandled");
        }
      }
    }
  }
  return QVariant();
}

int RulesTableModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid()) {
    return 0;
  }
  return mRules.size();
}

int RulesTableModel::columnCount(const QModelIndex &parent) const {
  if (parent.isValid()) {
    return 0;
  }
  return 4;
}

QVariant RulesTableModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }
  if(role == Qt::DisplayRole) {
    const auto& rule = mRules[index.row()];
    switch(index.column()) {
      case 0:{
        return SheetRules::sheetTypeToString(rule.getSheetType());
      } case 1: {
        return QString("%1 Teams").arg(rule.getTeamSize());
      } case 2: {
        if(qFuzzyCompare(rule.getPPR(), 0)) {
          return QString("Standard");
        }
        return QString("%1 PPR").arg(QString::number(rule.getPPR()));
      } case 3: {
        const PlayerLimits limits = rule.getLimits();
        return QString("%1 QBs | %2 RBs | %3 WRs | %4 TEs | %5 Flex | %6 DST | % K").arg(limits.quarterbacks)
                                                                                    .arg(limits.runningBacks)
                                                                                    .arg(limits.wideReceivers)
                                                                                    .arg(limits.tightEnds)
                                                                                    .arg(limits.flexes)
                                                                                    .arg(limits.DST)
                                                                                    .arg(limits.PK);
      }
    }
  }
  return QVariant();
}
