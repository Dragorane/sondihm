#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>

namespace Ui {
class accueil;
}

class accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = 0);
    ~accueil();

private slots:
    void on_Formulaire_clicked();

    void on_accueil_iconSizeChanged(const QSize &iconSize);

private:
    Ui::accueil *ui;
};

#endif // ACCUEIL_H
