QT += core
QT += network

QT -= gui

CONFIG += c++11

TARGET = QPortKnocking
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
           main.cpp \
           src/QPortKnocking.cpp

HEADERS += \
           include/QPortKnocking.h

INCLUDEPATH += \
           include/
