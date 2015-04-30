#include "mainformulaire.h"
#include "ui_mainformulaire.h"

MainFormulaire::MainFormulaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFormulaire)
{
    ui->setupUi(this);
}

MainFormulaire::~MainFormulaire()
{
    delete ui;
}
