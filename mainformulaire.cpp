#include "mainformulaire.h"
#include "ui_mainformulaire.h"

MainFormulaire::MainFormulaire(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainFormulaire) {
    ui->setupUi(this);
}

void MainFormulaire::on_CancelButton_clicked() {
	this->close();
}

void MainFormulaire::on_StatButton_clicked() {}

void MainFormulaire::on_AnswerButton_clicked() {}

MainFormulaire::~MainFormulaire() {
    delete ui;
}
