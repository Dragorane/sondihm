#include "dialogaccueil.h"
#include "ui_dialogaccueil.h"
#include "dialoggestioncompte.h"

DialogAccueil::DialogAccueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogAccueil)
{
    ui->setupUi(this);
}

DialogAccueil::~DialogAccueil()
{
    delete ui;
}

void DialogAccueil::on_GestionCompte_clicked(){
    DialogGestionCompte *dialog=new DialogGestionCompte;
    dialog->show();
}
