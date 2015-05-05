#include "mainformulaire.h"
#include "ui_mainformulaire.h"
#include "dialogformulaire.h"
#include "dialogstatistique.h"

MainFormulaire::MainFormulaire(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainFormulaire) {
    ui->setupUi(this);
    initForm();
}

void MainFormulaire::on_CancelButton_clicked() {
	this->close();
}

void MainFormulaire::on_StatButton_clicked() {
    global_id_form=ui->listForm->currentRow();
    DialogStatistique *dialog=new DialogStatistique;
    dialog->show();
}

void MainFormulaire::on_AnswerButton_clicked() {
    global_id_form=ui->listForm->currentRow();
    DialogFormulaire *dialog=new DialogFormulaire;
    dialog->show();
}

void MainFormulaire::on_CreateButton_clicked() {}

MainFormulaire::~MainFormulaire() {
    delete ui;
}

void MainFormulaire::initForm(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Formulaire order by idForm";
    query.prepare(req);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        while (query.next()) {
            ui->listForm->addItem(query.value(query.record().indexOf("nomForm")).toString());
        }
    }
}
