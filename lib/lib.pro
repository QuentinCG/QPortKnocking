QT += core
QT += network

QT -= gui

DEFINES += QPORTKNOCKING_LIBRARY


CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

CONFIG(release, debug|release): TARGET = QPortKnocking
else:CONFIG(debug, debug|release): TARGET = QPortKnockingd

TEMPLATE = lib

SOURCES += \
           src/QPortKnocking.cpp

HEADERS += \
           include/QPortKnocking.h \
           include/QPortKnocking_global.h

INCLUDEPATH += \
           include/

# Test coverage (linux in debug only)
unix:!macx:CONFIG(debug, debug|release): {
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov
}
