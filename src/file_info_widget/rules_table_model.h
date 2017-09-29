#ifndef RULESTABLEMODEL_H
#define RULESTABLEMODEL_H

#include <QAbstractTableModel>

// Rules:
//  Draft Type
//  Scoring Rules
//  Player Limits
//  Number of Teams

class RulesTableModel : public QAbstractTableModel
{
  Q_OBJECT

public:
  explicit RulesTableModel(QObject *parent = nullptr);

  // Header:
  QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

  // Basic functionality:
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // RULESTABLEMODEL_H
