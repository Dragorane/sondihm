#include "dialogformulaire.h"
#include "ui_dialogformulaire.h"

DialogFormulaire::DialogFormulaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogFormulaire)
{
    ui->setupUi(this);
}

DialogFormulaire::~DialogFormulaire()
{
    delete ui;
}
