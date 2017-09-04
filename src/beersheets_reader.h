/*!
  \file beersheets_reader.h
  \brief file to define BeerSheetsReader
*/

#ifndef BEERSHEETS_READER_H
#define BEERSHEETS_READER_H

#include <QtCore>
#include <QtXlsx>

#include "beersheet.h"

using namespace QXlsx;

/*!
  \class BeerSheetsReader
  \brief Class to read in Beersheet
  \extends QObject
 */
class BeerSheetsReader : public QObject {
  Q_OBJECT

public:
  BeerSheetsReader(QObject *parent = nullptr);
  ~BeerSheetsReader();

  BeerSheet* read(const QString &fileName);

protected:

private:
  bool readHeaderIntoBeerSheet(BeerSheet *sheet);
  bool readQuarterbacks(BeerSheet *sheet);
  Document* mFile = nullptr;

};

#endif //BEERSHEETS_READER_H
