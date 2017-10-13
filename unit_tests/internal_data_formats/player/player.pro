QT += testlib widgets
macx: CONFIG -= app_bundle

BEER_SHEETS_ROOT = ../../..

include($${BEER_SHEETS_ROOT}/beer_sheets_tool.pri)

HEADERS += $${INTERNAL_DATA_FORMATS}/player_data.h \
           $${COMMON_DIR}/common.h \
           $${INTERNAL_DATA_FORMATS}/player.h \

SOURCES += $${INTERNAL_DATA_FORMATS}/player_data.cpp \
           $${INTERNAL_DATA_FORMATS}/player.cpp \
           $${PWD}/player_tests.cpp \

INCLUDEPATH += $${INTERNAL_DATA_FORMATS}
INCLUDEPATH += $${COMMON_DIR}

