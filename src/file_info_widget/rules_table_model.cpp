#include "rules_table_model.h"

RulesTableModel::RulesTableModel(QObject *parent)
  : QAbstractTableModel(parent)
{
}

QVariant RulesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  // FIXME: Implement me!
}

int RulesTableModel::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  // FIXME: Implement me!
}

int RulesTableModel::columnCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return 0;

  // FIXME: Implement me!
}

QVariant RulesTableModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  // FIXME: Implement me!
  return QVariant();
}
