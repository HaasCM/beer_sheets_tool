
INTERNAL_DATA_FORMATS = $${PWD}
INCLUDEPATH += $${COMMON_DIR}

HEADERS += $${INTERNAL_DATA_FORMATS}/beersheet.h \
           $${INTERNAL_DATA_FORMATS}/player.h \
    $$PWD/player_data.h

SOURCES += $${INTERNAL_DATA_FORMATS}/beersheet.cpp \
           $${INTERNAL_DATA_FORMATS}/player.cpp \
    $$PWD/player_data.cpp
