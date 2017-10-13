/*!
  \file file_info_widget.cpp
  \brief File to implement the FileInfoWidget
*/

#include "file_info_widget.h"

/*!
  \brief Default constructor for the FileInfoWidget class
  \param parent QObject this instance is parented to
*/
FileInfoWidget::FileInfoWidget(QWidget *parent) :
  QWidget(parent) {
  setupUi(this);
  mRulesModel = new RulesTableModel(this);
  rulesTableView->setModel(mRulesModel);
}

/*!
  \brief Default destructor for the FileInfoWidget class
*/
FileInfoWidget::~FileInfoWidget() {

}
