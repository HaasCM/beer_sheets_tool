/*!
  \file main.cpp
  \brief The Main file for the BeerSheetsTool application
*/
#include "beersheets_mainwindow.h"
#include <QApplication>

/*!
  \brief The main function for the BeerSheetsTool applicaiton
  \param argc intereger
  \param argv char*
  \return the application exit code
*/
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  a.setApplicationDisplayName("BeerSheets Analyzer");
  a.setApplicationName("BeerSheets Analyzer");
  a.setApplicationVersion("0.1");
  a.setOrganizationName("Cody Haas");
  a.setOrganizationDomain("https://github.com/HaasCM");
  BeerSheetsMainWindow w;
  w.show();

  return a.exec();
}
