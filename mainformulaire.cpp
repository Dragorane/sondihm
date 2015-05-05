#include "mainformulaire.h"
#include "ui_mainformulaire.h"
#include "dialogformulaire.h"
#include "dialogstatistique.h"
#include "dialogcreateform.h"

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
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select count(*) from Valeurs, Champs where Valeurs.idChamps=Champs.idChamps AND idForm=:idform AND idPers=:id";
    query.prepare(req);
    query.bindValue(":idform",ui->listForm->currentRow());
    query.bindValue(":id",recuperIdPers());
    if(!query.exec()){
        erreurBdd(query);
    }else{
        query.next();
        qDebug() << query.value(0).toInt();

        if ((query.value(0).toInt())>0){
            erreurAccesForm();
        }else{
            global_id_form=ui->listForm->currentRow();
            DialogFormulaire *dialog=new DialogFormulaire;
            dialog->show();
        }
    }
}

void MainFormulaire::on_CreateButton_clicked() {
    DialogCreateForm *dialog=new DialogCreateForm;
    dialog->show();
}

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
int MainFormulaire::recuperIdPers(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="SELECT idPers from Personne where identifiantPers=:idPers";
    query.prepare(req);
    query.bindValue(":idPers",global_id);
    if(!query.exec()){
        erreurBdd(query);
        return -1;
    }else{
        query.next();
        return query.value(0).toInt();
    }
}
