#ifndef MAINFORMULAIRE_H
#define MAINFORMULAIRE_H

#include <QMainWindow>
#include <QtDebug>
#include <QMessageBox>
#include <QString>
#include <QComboBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QtSql>
#include <iostream>

namespace Ui {
class MainFormulaire;
}

class MainFormulaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainFormulaire(QWidget *parent = 0);
    ~MainFormulaire();

private slots:
    void on_CancelButton_clicked();
    void on_StatButton_clicked();
    void on_AnswerButton_clicked();
    void on_CreateButton_clicked();
    int recuperIdPers();

private:
    Ui::MainFormulaire *ui;
    void initForm();
};

#endif // MAINFORMULAIRE_H
