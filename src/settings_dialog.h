/*!
  \file settings_dialog.h
  \brief file to define the SettingsDialog class
*/

#ifndef SETTINGS_DIALOG_H
#define SETTINGS_DIALOG_H

#include "ui_settings_dialog_base.h"

/*!
  \class SettingsDialog
  \brief Handles the Settings Dialog UI
 */
class SettingsDialog : public QDialog, private Ui::SettingsDialog
{
  Q_OBJECT

public:
  explicit SettingsDialog(QWidget *parent = 0);

public slots:
  void accept();
private:
  QString getDir(QString desc);

};
#endif // SETTING_SDIALOG_H
