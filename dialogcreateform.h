#ifndef DIALOGCREATEFORM_H
#define DIALOGCREATEFORM_H

#include <QDialog>
#include <QComboBox>
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
class DialogCreateForm;
}

class DialogCreateForm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateForm(QWidget *parent = 0);
    ~DialogCreateForm();

private:
    Ui::DialogCreateForm *ui;
    void initType();

private slots:
    void validNewForm();
};

#endif // DIALOGCREATEFORM_H
