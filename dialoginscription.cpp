#include "dialoginscription.h"
#include "ui_dialoginscription.h"

DialogInscription::DialogInscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInscription)
{
    ui->setupUi(this);
}

DialogInscription::~DialogInscription()
{
    delete ui;
}

void DialogInscription::on_CancelButton_clicked()
{
    this->close();
}
