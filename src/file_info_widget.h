/*!
  \file file_info_widget.h
  \brief Definition of the FileInfoWidget class
*/

#ifndef FILE_INFO_WIDGET_H
#define FILE_INFO_WIDGET_H

#include "ui_file_info_widget_base.h"
#include "beersheet_tree_item.h"

/*!
  \brief Class to handle Logic to DisplayFileInfo business logic
*/
class FileInfoWidget : public QWidget, private Ui::FileInfoWidgetBase {
  Q_OBJECT

public:
  FileInfoWidget(QWidget *parent = nullptr);
  ~FileInfoWidget();

public slots:
  void onBeerSheetAdded(const std::shared_ptr<BeerSheet> &sheet);

private:
  void addBeerSheet(const std::shared_ptr<BeerSheet> &sheet);
  BeerSheetTreeItem* findInsertion(const BeerSheetTreeItem &item);
};

#endif // FILE_INFO_WIDGET_H
