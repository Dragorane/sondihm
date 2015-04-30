#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"
#include "accueil.h"

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

void DialogConnexion::on_CancelButton_clicked()
{
    this->close();
}

void DialogConnexion::on_SubmitButton_clicked()
{
    accueil *dialog=new accueil;
    dialog->show();
}
