QT += testlib widgets
macx: CONFIG -= app_bundle

BEER_SHEETS_ROOT = ../../..

include($${BEER_SHEETS_ROOT}/beer_sheets_tool.pri)

HEADERS += $${INTERNAL_DATA_FORMATS}/player_data.h \

SOURCES += $${INTERNAL_DATA_FORMATS}/player_data.cpp \
           $${PWD}/player_data_tests.cpp \

INCLUDEPATH += $${INTERNAL_DATA_FORMATS}
INCLUDEPATH += $${COMMON_DIR}

