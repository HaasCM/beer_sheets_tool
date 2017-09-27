#-------------------------------------------------
#
# Project created by QtCreator 2017-07-23T11:41:04
#
#-------------------------------------------------

QT       += core gui xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeerSheets_Analyzer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include($${PWD}/beer_sheets_tool.pri)
include($${SOURCE_DIR}/internal_data_formats/internal_data_formats.pri)
INCLUDEPATH += $${INTERNAL_DATA_FORMATS}
INCLUDEPATH += $${SOURCE_DIR}

SOURCES += \
        $${SOURCE_DIR}/main.cpp \
        $${SOURCE_DIR}/beersheets_mainwindow.cpp \
        $${SOURCE_DIR}/abstract_file_reader.cpp \
        $${SOURCE_DIR}/settings_dialog.cpp \
        $${SOURCE_DIR}/beersheets_reader.cpp \
        $${SOURCE_DIR}/file_info_widget.cpp

HEADERS += \
        $${SOURCE_DIR}/beersheets_mainwindow.h \
        $${SOURCE_DIR}/abstract_file_reader.h \
        $${SOURCE_DIR}/settings_dialog.h \
        $${SOURCE_DIR}/beersheets_reader.h \
        $${COMMON_DIR}/common.h \
        $${SOURCE_DIR}/file_info_widget.h

FORMS += \
        $${SOURCE_DIR}/beersheets_mainwindow_base.ui \
        $${SOURCE_DIR}/settings_dialog_base.ui \
        $${SOURCE_DIR}/file_info_widget_base.ui

