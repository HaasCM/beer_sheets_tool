/*!
  \file file_info_widget.h
  \brief file to define the FileInfoWidget
*/

#ifndef FILE_INFO_WIDGET_H
#define FILE_INFO_WIDGET_H

#include "rules_table_model.h"
#include "ui_file_info_widget_base.h"

/*!
  \brief Class to handle Logic to DisplayFileInfo business logic
*/
class FileInfoWidget : public QWidget, private Ui::FileInfoWidgetBase {
  Q_OBJECT

public:
  FileInfoWidget(QWidget *parent = nullptr);
  ~FileInfoWidget();

public slots:

private:
  RulesTableModel *mRulesModel = nullptr;
};

#endif // FILE_INFO_WIDGET_H
