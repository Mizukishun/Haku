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
    favoritelist.cpp \
    mobilemanage.cpp \
    download.cpp \
    more.cpp \
    lyricwidget.cpp \
    lyframe.cpp \
    packupwidget.cpp \
    toolgroup/toolgroup.cpp \
    toolgroup/selfgroup.cpp

HEADERS  += widget.h \
    secframe.h \
    musiclist.h \
    favoritelist.h \
    mobilemanage.h \
    download.h \
    more.h \
    lyricwidget.h \
    lyframe.h \
    packupwidget.h \
    toolgroup/toolgroup.h \
    toolgroup/selfgroup.h

RESOURCES += \
    res.qrc
