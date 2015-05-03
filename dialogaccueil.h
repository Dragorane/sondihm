#ifndef DIALOGACCUEIL_H
#define DIALOGACCUEIL_H

#include <QMainWindow>

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
    void on_GestionCompte_clicked();

};

#endif // DIALOGACCUEIL_H
