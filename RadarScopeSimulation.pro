QT += core gui quick widgets
CONFIG += c++17 release
TARGET = RadarScopeSimulation
TEMPLATE = app

# CRITICAL FIX: Add subdirectories to include path for quoted #include resolution
INCLUDEPATH += \
    $$PWD/src/model \
    $$PWD/src/controller

SOURCES += \
    main.cpp \
    src/model/Target.cpp \
    src/model/RadarModel.cpp \
    src/controller/RadarController.cpp

HEADERS += \
    src/model/Target.h \
    src/model/RadarModel.h \
    src/controller/RadarController.h

RESOURCES += resources.qrc

DESTDIR = $$PWD/build/release
OBJECTS_DIR = $$PWD/build/.obj
MOC_DIR = $$PWD/build/.moc
RCC_DIR = $$PWD/build/.rcc

DEFINES += QT_HIGHDPI_AWARE
QMAKE_CXXFLAGS += -Wall -Wextra