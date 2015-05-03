#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

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

#include "dberrors.h"
#include "globaldata.h"

#define q2c(string) string.toStdString()

namespace Ui {
class DialogInscription;
}

class DialogInscription : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInscription(QWidget *parent = 0);
    ~DialogInscription();

private slots:
    void on_CancelButton_clicked();
    void on_SubmitButton_clicked();

private:
    Ui::DialogInscription *ui;
    QSqlDatabase db;
    void initchamps();
    void closePage();
    int newIdUser();
};

#endif // DIALOGINSCRIPTION_H
