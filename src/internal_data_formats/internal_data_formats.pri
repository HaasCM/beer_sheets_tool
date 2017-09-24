
INTERNAL_DATA_FORMATS = $${PWD}
INCLUDEPATH += $${COMMON_DIR}

HEADERS += $${INTERNAL_DATA_FORMATS}/beersheet.h \
           $${INTERNAL_DATA_FORMATS}/player.h \
           $${INTERNAL_DATA_FORMATS}/player_data.h

SOURCES += $${INTERNAL_DATA_FORMATS}/beersheet.cpp \
           $${INTERNAL_DATA_FORMATS}/player.cpp \
           $${INTERNAL_DATA_FORMATS}/player_data.cpp
