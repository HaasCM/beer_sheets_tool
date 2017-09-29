/*!
  \file file_info_widget.cpp
  \brief File to implement the FileInfoWidget class
*/

#include "file_info_widget.h"

/*!
  \brief Default constructor for the FileInfoWidget class
  \param parent QObject this instance is parented to
*/
FileInfoWidget::FileInfoWidget(QWidget *parent) :
  QWidget(parent) {
  setupUi(this);
}

/*!
  \brief Default destructor for the FileInfoWidget class
*/
FileInfoWidget::~FileInfoWidget() {

}

void FileInfoWidget::onBeerSheetAdded(const std::shared_ptr<BeerSheet> &sheet) {
  addBeerSheet(sheet);
}

void FileInfoWidget::addBeerSheet(const std::shared_ptr<BeerSheet> &sheet) {
  QStringList list;
  list << sheet->getDate().toString() << "Snake" << QString("%1 Teams").arg(12) << "1 PPR";
  qDebug() << "Added";
  fileTreeWidget->addTopLevelItem(itemToAdd);
}
