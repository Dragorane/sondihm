#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T13:55:52
#
#-------------------------------------------------

QT       += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialoginscription.cpp \
    dialogconnexion.cpp \
    mainformulaire.cpp \
    dialogformulaire.cpp \
    dialogstatistique.cpp \
    dialogaccueil.cpp \
    dialoggestioncompte.cpp \
    dberrors.cpp \
    globaldata.cpp

HEADERS  += mainwindow.h \
    dialoginscription.h \
    dialogconnexion.h \
    mainformulaire.h \
    dialogformulaire.h \
    dialogstatistique.h \
    dialogaccueil.h \
    dberrors.h \
    globaldata.h \
    dialoggestioncompte.h

FORMS    += mainwindow.ui \
    dialoginscription.ui \
    dialogconnexion.ui \
    mainformulaire.ui \
    dialogformulaire.ui \
    dialogstatistique.ui \
    dialogaccueil.ui \
    dialoggestioncompte.ui
