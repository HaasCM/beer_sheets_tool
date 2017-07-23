/*!
  \file beersheets_mainwindow.h
  \brief file to declare the BeerSheetsMainWindow class
*/

#ifndef BEERSHEETS_MAINWINDOW_H
#define BEERSHEETS_MAINWINDOW_H

#include <ui_beersheets_mainwindow_base.h>


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
};

#endif // BEERSHEETS_MAINWINDOW_H
