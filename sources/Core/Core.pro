#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T00:15:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += game.cpp \
    field.cpp \
    ship.cpp \
    cell.cpp

HEADERS += game.h \
    field.h \
    ship.h \
    cell.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
