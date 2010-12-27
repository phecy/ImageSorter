#-------------------------------------------------
#
# Project created by QtCreator 2010-11-15T20:33:16
#
#-------------------------------------------------

QT       += core
QT       += opengl
QT       += gui

TARGET = ppmFinal
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    harmony.cpp \
    grey.cpp \
    findDups.cpp \
    exposure.cpp \
    color.cpp \
    blurdetect.cpp \
    display.cpp \
    insertionsort.cpp

HEADERS += \
    harmony.h \
    grey.h \
    findDups.h \
    exposure.h \
    colorUtility.h \
    color.h \
    blurdetect.h \
    display.h \
    insertionsort.h

win32 {
QMAKE_LFLAGS += -static-libgcc
}

FORMS += \
    display.ui
