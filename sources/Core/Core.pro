#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T00:15:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ship.cpp \
    cell.cpp \
    field.cpp \
    game.cpp

HEADERS += ship.h \
    cell.h \
    enums.h \
    field.h \
    game.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
