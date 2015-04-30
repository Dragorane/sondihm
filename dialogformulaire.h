#ifndef DIALOGFORMULAIRE_H
#define DIALOGFORMULAIRE_H

#include <QMainWindow>

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
};

#endif // DIALOGFORMULAIRE_H
