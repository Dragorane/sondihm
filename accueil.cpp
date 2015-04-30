#include "accueil.h"
#include "mainformulaire.h"
#include "ui_accueil.h"

accueil::accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::accueil)
{
    ui->setupUi(this);
}

accueil::~accueil()
{
    delete ui;
}

void accueil::on_Formulaire_clicked(){
    MainFormulaire *dialog=new MainFormulaire;
    dialog->show();
}
