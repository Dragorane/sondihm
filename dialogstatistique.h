#ifndef DIALOGSTATISTIQUE_H
#define DIALOGSTATISTIQUE_H

#include <sstream>
#include <string>
#include <iostream>
#include <QMainWindow>
#include "dberrors.h"
#include "globaldata.h"

namespace Ui {
class DialogStatistique;
}

class DialogStatistique : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogStatistique(QWidget *parent = 0);
    ~DialogStatistique();

private:
    Ui::DialogStatistique *ui;
    void getStats();
};

#endif // DIALOGSTATISTIQUE_H
