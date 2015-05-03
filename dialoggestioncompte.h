#ifndef DIALOGGESTIONCOMPTE_H
#define DIALOGGESTIONCOMPTE_H

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
#include "globaldata.h"
#include "dberrors.h"

namespace Ui {
class DialogGestionCompte;
}

class DialogGestionCompte : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGestionCompte(QWidget *parent = 0);
    ~DialogGestionCompte();

private slots:
    void on_CancelButton_clicked();

    void on_SubmitButton_clicked();

private:
    Ui::DialogGestionCompte *ui;
    void closePage();
    void initchamps();
};

#endif // DIALOGGESTIONCOMPTE_H
