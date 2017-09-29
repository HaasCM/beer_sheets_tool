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
