#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "dialoginscription.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_InscriptionButton_clicked();    
    void on_ConnectionButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
