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
    toolgroup/selfgroup.cpp \
    toolgroup/singlemusic.cpp \
    toolgroup/simplifiedmusic.cpp \
    toolgroup/audiolist.cpp \
    download/displaywidget.cpp \
    download/singledisplay.cpp \
    download/download.cpp


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
    toolgroup/selfgroup.h \
    toolgroup/singlemusic.h \
    toolgroup/simplifiedmusic.h \
    toolgroup/audiolist.h \
    download/displaywidget.h \
    download/singledisplay.h \
    download/download.h


RESOURCES += \
    res.qrc
