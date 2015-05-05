#ifndef MAINFORMULAIRE_H
#define MAINFORMULAIRE_H

#include <QMainWindow>

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

private:
    Ui::MainFormulaire *ui;
};

#endif // MAINFORMULAIRE_H
