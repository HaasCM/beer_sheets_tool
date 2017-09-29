/*!
  \file beersheets_mainwindow.cpp
  \brief file to declare the beersheets main window
*/

#include "beersheets_mainwindow.h"
#include "settings_dialog.h"

#include <QFileDialog>
#include <QSettings>

/*!
  \fn BeerSheetsMainWindow::BeerSheetsMainWindow(QWidget *parent)
  \brief Default constructor for the BeerSheets main window
*/
BeerSheetsMainWindow::BeerSheetsMainWindow(QWidget *parent) :
QMainWindow(parent) {
  mReader = new BeerSheetsReader(this);
  setupUi(this);
  setWindowTitle("BeerSheets Analyzer");
  fileImportBeerSheet->setShortcut(QKeySequence(Qt::ControlModifier + Qt::Key_O));
  fileExportBeerSheet->setShortcut(QKeySequence(Qt::ControlModifier + Qt::Key_S));

  connect(fileSettings, &QAction::triggered,
         this, &BeerSheetsMainWindow::onSettings);
  connect(fileImportBeerSheet, &QAction::triggered,
          this, &BeerSheetsMainWindow::onImportFile);
  connect(fileExportBeerSheet, &QAction::triggered,
          this, &BeerSheetsMainWindow::onExportFile);
  show();
}

/*!
  \fn BeerSheetsMainWindow::~BeerSheetsMainWindow()
  \brief default destructor for the BeerSheetsMainWindow class
*/

BeerSheetsMainWindow::~BeerSheetsMainWindow() {
}

/*!
  \fn void BeerSheetsMainWindow::onImportFile()
  \brief handles the Import File triggered signal
*/

void BeerSheetsMainWindow::onImportFile() {
  QSettings settings;
  QString fileName = QFileDialog::getOpenFileName(this, "Import Beer Sheets",
                                                  settings.value("BeerSheets/Paths/Import", QDir::homePath()).toString(),
                                                  tr("Excel Worksheet (*.xlsx) ;; HDF5 (*.h5)"));
  fileContents->onBeerSheetAdded(mReader->read(fileName));
}

/*!
  \fn void BeerSheetsMainWindow::onExportFile()
  \brief hands the Export File triggered signal
*/

void BeerSheetsMainWindow::onExportFile() {
  QSettings settings;
  QString fileName = QFileDialog::getSaveFileName(this, "Export Beer Sheets",
                                                  settings.value("BeerSheets/Paths/Export", QDir::homePath()).toString(),
                                                  "Beer Sheets (*.h5)");
}

/*!
  \fn void BeerSheetsMainWindow::onSettings()
  \brief handles the settings triggered signal
*/

void BeerSheetsMainWindow::onSettings() {
  SettingsDialog dialog;
  dialog.exec();
}



