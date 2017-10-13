BEERSHEETS_ROOT = ../../..

include{BEERSHEETS_ROOT/beer_sheets_tool.pri}

INCLUDEPATH += $${COMMON_DIR}

HEADERS += $${PWD}/beersheet.h \
           $${PWD}/player.h \
           $${PWD}/player_data.h \
           $${PWD}/sheet_rules.h

SOURCES += $${PWD}/beersheet.cpp \
           $${PWD}/player.cpp \
           $${PWD}/player_data.cpp \
           $${PWD}/sheet_rules.cpp
