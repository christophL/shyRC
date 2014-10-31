#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T08:34:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shyRC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    server.cpp \
    channel.cpp

HEADERS  += mainwindow.h \
    user.h \
    server.h \
    channel.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
