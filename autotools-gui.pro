#-------------------------------------------------
#
# Project created by QtCreator 2017-12-25T10:53:45
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autotools-gui
TEMPLATE = app

prefix=/usr/local
target.files += autotools-gui
target.path += $$prefix/bin

SOURCES += main.cpp\
        mainwindow.cpp \
    configurator.cpp

HEADERS  += mainwindow.h \
    target.h \
    configs.h \
    configurator.h \
    headers.h

FORMS    += mainwindow.ui

INSTALLS += target
