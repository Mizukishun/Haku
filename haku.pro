#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T12:38:34
#
#-------------------------------------------------

QT       += core gui
Qt       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = haku
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    secframe.cpp \
    musiclist.cpp \
    favoritelist.cpp

HEADERS  += widget.h \
    secframe.h \
    musiclist.h \
    favoritelist.h

RESOURCES += \
    res.qrc
