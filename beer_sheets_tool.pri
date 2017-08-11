# Beer Sheets Tool pri file
#

# Setting project paths
BEERSHEETS_TOOL_ROOT = $${PWD}
SOURCE_DIR = $${BEERSHEETS_TOOL_ROOT}/src/
COMMON_DIR = $${SOURCE_DIR}/common/

# Setting lib paths
win32:LIB_PATH = C:/dev/Libraries
unix:LIB_PATH = /usr/local

DESTDIR = "$${BEERSHEETS_TOOL_ROOT}/bin"
OBJECTS_DIR = "$${BEERSHEETS_TOOL_ROOT}/tmp/obj"
MOC_DIR = "$${BEERSHEETS_TOOL_ROOT}/tmp/moc"
UI_DIR = "$${BEERSHEETS_TOOL_ROOT}/tmp/uic"
RCC_DIR = "$${BEERSHEETS_TOOL_ROOT}/tmp/rcc"

win32:HDF5_PATH=$${LIB_PATH}/HDF5
unix:HDF5_PATH=$${LIB_PATH}/hdf5
