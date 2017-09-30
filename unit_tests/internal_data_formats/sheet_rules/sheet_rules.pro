QT += testlib widgets
macx: CONFIG -= app_bundle

BEER_SHEETS_ROOT = ../../..

include($${BEER_SHEETS_ROOT}/beer_sheets_tool.pri)

HEADERS += $${INTERNAL_DATA_FORMATS}/sheet_rules.h \

SOURCES += $${INTERNAL_DATA_FORMATS}/sheet_rules.cpp \
           $${PWD}/sheet_rules_tests.cpp \

INCLUDEPATH += $${INTERNAL_DATA_FORMATS}
INCLUDEPATH += $${COMMON_DIR}

