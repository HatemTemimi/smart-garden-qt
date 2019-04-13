#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T21:23:41
#
#-------------------------------------------------

QT       += core gui
QT       += sql multimedia
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet1
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

CONFIG += c++11
CONFIG +=console
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    lampes.cpp \
    capteurs.cpp \
    connexion.cpp \
    gestion2.cpp \
    notification.cpp \
    arduino.cpp

HEADERS += \
        mainwindow.h \
    lampes.h \
    capteurs.h \
    connexion.h \
    gestion2.h \
    notification.h \
    arduino.h

FORMS += \
        mainwindow.ui \
    gestion2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc