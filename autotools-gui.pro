#-------------------------------------------------
#
# Project created by QtCreator 2017-12-25T10:53:45
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autotools-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    target.cpp

HEADERS  += mainwindow.h \
    target.h \
    configs.h

FORMS    += mainwindow.ui
