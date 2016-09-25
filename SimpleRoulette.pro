#-------------------------------------------------
#
# Project created by QtCreator 2016-09-25T15:54:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleRoulette
TEMPLATE = app
TRANSLATIONS += sr_ru_RU.ts sr_ru_EN.ts

SOURCES += main.cpp\
        srwindow.cpp \
    randomadapter.cpp \
    roulettesourcestorage.cpp

HEADERS  += srwindow.h \
    randomadapter.h \
    roulettesourcestorage.h

FORMS    += srwindow.ui

OTHER_FILES += sr_ru_RU.ts sr_ru_EN.ts
