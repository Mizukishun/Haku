#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T12:38:34
#
#-------------------------------------------------

QT       += core gui
QT       += core
QT       += multimedia
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = haku
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        widget.cpp \
    secframe.cpp \
    musiclist.cpp \
    favoritelist.cpp \
    mobilemanage.cpp \
    download.cpp \
    more.cpp \
    packupwidget.cpp \
    toolgroup/selfgroup.cpp \
    toolgroup/singlemusic.cpp \
    toolgroup/simplifiedmusic.cpp \
    toolgroup/audiolist.cpp \
    download/displaywidget.cpp \
    download/singledisplay.cpp \
    lyric/lyricwidget.cpp \
    lyric/lyricfile.cpp


HEADERS  += widget.h \
    secframe.h \
    musiclist.h \
    favoritelist.h \
    mobilemanage.h \
    download.h \
    more.h \
    packupwidget.h \
    toolgroup/selfgroup.h \
    toolgroup/singlemusic.h \
    toolgroup/simplifiedmusic.h \
    toolgroup/audiolist.h \
    download/displaywidget.h \
    download/singledisplay.h \
    lyric/lyricwidget.h \
    lyric/lyricfile.h


RESOURCES += \
    res.qrc
