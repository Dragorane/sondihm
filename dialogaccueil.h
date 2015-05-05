#ifndef DIALOGACCUEIL_H
#define DIALOGACCUEIL_H

#include <QMainWindow>

#include "mainformulaire.h"
#include "ui_dialogaccueil.h"
#include "dialoggestioncompte.h"

namespace Ui {
class DialogAccueil;
}

class DialogAccueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogAccueil(QWidget *parent = 0);
    ~DialogAccueil();

private:
    Ui::DialogAccueil *ui;

private slots:
    void slotgestioncompte();
    void slotmainform();
};

#endif // DIALOGACCUEIL_H
