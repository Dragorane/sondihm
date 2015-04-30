#include "dialogstatistique.h"
#include "ui_dialogstatistique.h"

DialogStatistique::DialogStatistique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogStatistique)
{
    ui->setupUi(this);
}

DialogStatistique::~DialogStatistique()
{
    delete ui;
}
