#-------------------------------------------------
#
# Project created by QtCreator 2018-10-01T20:16:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = os_prj
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    ../os_541/file.cpp \
    ../os_541/file_mangement.cpp \
    ../os_541/global.cpp \
    ../os_541/memory.cpp \
    ../os_541/Operation.cpp \
    ../os_541/PCB.cpp \
    ../os_541/Process.cpp \
    ../os_541/run.cpp \
    ../os_541/running.cpp \
    ../os_541/scheduleAlgorithm.cpp \
    ../os_541/terminated.cpp \
    ../os_541/waiting.cpp \
    ../os_541/stdafx.cpp \
    ../os_541/new.cpp \
    ../os_541/ready.cpp

HEADERS += \
        mainwindow.h \
    dialog.h \
    ../os_541/file.h \
    ../os_541/file_mangement.h \
    ../os_541/global.h \
    ../os_541/memory.h \
    ../os_541/Operation.h \
    ../os_541/PCB.h \
    ../os_541/Process.h \
    ../os_541/run.h \
    ../os_541/running.h \
    ../os_541/scheduleAlgorithm.h \
    ../os_541/targetver.h \
    ../os_541/TC_ThreadQueue.h \
    ../os_541/terminated.h \
    ../os_541/stdafx.h \
    ../os_541/targetver.h \
    ../os_541/waiting.h \
    ../os_541/new.h \
    ../os_541/ready.h

FORMS += \
        mainwindow.ui \
    dialog.ui

DISTFILES +=

RESOURCES += \
    res.qrc
