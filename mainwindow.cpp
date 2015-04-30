#include "mainwindow.h"
#include "dialoginscription.h"
#include "dialogconnexion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_InscriptionButton_clicked()
{
    DialogInscription *dialog = new DialogInscription;
    dialog->show();
}

void MainWindow::on_ConnectionButton_clicked()
{
    DialogConnexion *dialog = new DialogConnexion;
    dialog->show();
}
