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
    serverdialog.cpp \
    connection.cpp \
    command.cpp \
    join_command.cpp \
    msg_command.cpp

HEADERS  += mainwindow.h \
    user.h \
    server.h \
    serverdialog.h \
    connection.h \
    logger.h \
    command.h \
    join_command.h \
    msg_command.h

FORMS    += mainwindow.ui \
    serverdialog.ui

QMAKE_CXXFLAGS += -std=c++11

unix: LIBS += -L$$PWD/libircclient/ -lircclient

INCLUDEPATH += $$PWD/libircclient
DEPENDPATH += $$PWD/libircclient
