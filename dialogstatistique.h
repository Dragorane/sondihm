#ifndef DIALOGSTATISTIQUE_H
#define DIALOGSTATISTIQUE_H

#include <QMainWindow>

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
};

#endif // DIALOGSTATISTIQUE_H
