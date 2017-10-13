/*!
  \file settings_dialog.cpp
  \brief file to define the SettingsDialog
*/
#include <QSettings>
#include <QFileDialog>
#include <QDebug>

#include "settings_dialog.h"

/*!
  \fn SettingsDialog::SettingsDialog(QWidget *parent)
  \brief Default constructor for the settings dialog class
*/
SettingsDialog::SettingsDialog(QWidget *parent) :
  QDialog(parent) {
  setupUi(this);
  QSettings settings;
  importLineEdit->setText(settings.value("BeerSheets/Paths/Import", QDir::homePath()).toString());
  exportLineEdit->setText(settings.value("BeerSheets/Paths/Export", QDir::homePath()).toString());
    connect(importButton, &QPushButton::clicked,
            [this]() { importLineEdit->setText(getDir("Import Directory")); });
    connect(exportButton, &QPushButton::clicked,
            [this]() { exportLineEdit->setText(getDir("Export Directory")); });
}

/*!
  \fn void SettingsDialog::accept()
  \brief slot to handle the accepting of the dialog
*/

void SettingsDialog::accept() {
  QSettings settings;
  settings.setValue("BeerSheets/Paths/Import", importLineEdit->text());
  settings.setValue("BeerSheets/Paths/Export", exportLineEdit->text());
  QDialog::accept();
}

/*!
  \fn QString SettingsDialog::getDir(QString &desc)
  \brief opens a get existing dir dialog and returns the selection
*/

QString SettingsDialog::getDir(QString desc) {
  return QFileDialog::getExistingDirectory(this,
                                           desc,
                                           QDir::rootPath(),
                                           QFileDialog::ShowDirsOnly |
                                           QFileDialog::DontResolveSymlinks);
}
