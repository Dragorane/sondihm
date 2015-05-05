#ifndef DIALOGFORMULAIRE_H
#define DIALOGFORMULAIRE_H

#include <QMainWindow>
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
#include <QRadioButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QDateEdit>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QFormLayout>
#include <vector>
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
    std::vector<QCheckBox *> lescheckbox;
    std::vector<QSpinBox *> lesspins;
    std::vector<QRadioButton *> lesradiosbutt;

private:
    Ui::DialogFormulaire *ui;
    void initForm();
    void initChamps();
    void initSousChamps(int id, QLabel * lab);
    void initspinbox(int id,QLabel * lab);
    void insertcheckbox();
    void insertspinbox();
    void insertradiobox();

private slots:
    void on_SubmitButton_clicked();
};

#endif // DIALOGFORMULAIRE_H
