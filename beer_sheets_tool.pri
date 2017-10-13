# Beer Sheets Tool pri file
#

# Setting project paths
BEERSHEETS_ROOT = $${PWD}
BEERSHEETS_TOOL = $${BEERSHEETS_ROOT}/beer_sheets_tool
SOURCE_DIR = $${BEERSHEETS_TOOL}
COMMON_DIR = $${SOURCE_DIR}/common

FILE_INFO_WIDGET = $${SOURCE_DIR}/file_info_widget
INTERNAL_DATA_FORMATS = $${SOURCE_DIR}/internal_data_formats

# Setting lib paths
win32:LIB_PATH = C:/dev/Libraries
unix:LIB_PATH = /usr/local

DESTDIR = "$${BEERSHEETS_ROOT}/bin"
OBJECTS_DIR = "$${BEERSHEETS_ROOT}/tmp/obj"
MOC_DIR = "$${BEERSHEETS_ROOT}/tmp/moc"
UI_DIR = "$${BEERSHEETS_ROOT}/tmp/uic"
RCC_DIR = "$${BEERSHEETS_ROOT}/tmp/rcc"

win32:HDF5_PATH=$${LIB_PATH}/HDF5
unix:HDF5_PATH=$${LIB_PATH}/hdf5
