#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T13:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialoginscription.cpp \
    dialogconnexion.cpp \
    accueil.cpp \
    mainformulaire.cpp \
    dialogformulaire.cpp \
    dialogstatistique.cpp

HEADERS  += mainwindow.h \
    dialoginscription.h \
    dialogconnexion.h \
    accueil.h \
    mainformulaire.h \
    dialogformulaire.h \
    dialogstatistique.h

FORMS    += mainwindow.ui \
    dialoginscription.ui \
    dialogconnexion.ui \
    accueil.ui \
    mainformulaire.ui \
    dialogformulaire.ui \
    dialogstatistique.ui
