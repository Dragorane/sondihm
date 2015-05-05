#ifndef DIALOGFORMULAIRE_H
#define DIALOGFORMULAIRE_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QString>
#include <QComboBox>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#include <QtGlobal>
#include "globaldata.h"
#include "dberrors.h"

namespace Ui {
class DialogFormulaire;
}

class DialogFormulaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogFormulaire(QWidget *parent = 0);
    ~DialogFormulaire();

private:
    Ui::DialogFormulaire *ui;
    void initForm();
    void initChamps();
    void initSousChamps();
};

#endif // DIALOGFORMULAIRE_H
