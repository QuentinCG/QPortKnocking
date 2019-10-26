QT += core
QT += network

QT -= gui

CONFIG += c++11

CONFIG(release, debug|release): TARGET = example
CONFIG(debug, debug|release): TARGET = exampled

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
           main.cpp

INCLUDEPATH += \
           $$PWD/../lib/include

DEPENDPATH += \
           $$PWD/../lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -lQPortKnocking
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -lQPortKnockingd
else:unix: LIBS += -L$$OUT_PWD/../lib/ -llibQPortKnocking
