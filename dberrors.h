#ifndef DBERRORS_H
#define DBERRORS_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QString>
#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#include <QtGlobal>

// Fonctions pour gérer les erreurs en rapport avec la BDD

void erreurRequete();

void erreurBdd(QSqlQuery query);

void erreurId();
    
#endif
