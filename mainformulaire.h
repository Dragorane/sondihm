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

private:
    Ui::MainFormulaire *ui;
};

#endif // MAINFORMULAIRE_H
