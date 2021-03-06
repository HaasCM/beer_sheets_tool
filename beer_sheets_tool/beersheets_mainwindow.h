/*!
  \file beersheets_mainwindow.h
  \brief file to declare the BeerSheetsMainWindow
*/

#ifndef BEERSHEETS_MAINWINDOW_H
#define BEERSHEETS_MAINWINDOW_H

#include <ui_beersheets_mainwindow_base.h>

#include "beersheets_reader.h"


/*!
  \class BeerSheetsMainWindow
  \brief The BeerSheetsMainWindow class
*/
class BeerSheetsMainWindow : public QMainWindow, private Ui::BeerSheetsMainWindow {
  Q_OBJECT

public:
  explicit BeerSheetsMainWindow(QWidget *parent = 0);
  ~BeerSheetsMainWindow();

private slots:
  void onImportFile();
  void onExportFile();
  void onSettings();
private:
  BeerSheetsReader *mReader; //!< Pointer to Object to read the beer sheets
};

#endif // BEERSHEETS_MAINWINDOW_H
