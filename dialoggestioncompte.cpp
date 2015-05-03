#include "dialoggestioncompte.h"
#include "ui_dialoggestioncompte.h"

DialogGestionCompte::DialogGestionCompte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGestionCompte)
{
    ui->setupUi(this);
    initchamps();
}

DialogGestionCompte::~DialogGestionCompte()
{
    delete ui;
}

void DialogGestionCompte::on_CancelButton_clicked()
{
    closePage();
}

//initialisation des champs du formulaire avec la bdd
void DialogGestionCompte::initchamps(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Personne where identifiantPers=:id";
    query.prepare(req);
    query.bindValue(":id",global_id);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        query.next();
        ui->nbAnimauxSpinBox->setValue(query.value(query.record().indexOf("nbAnimPers")).toInt());
        ui->nbEnfantSpinBox->setValue(query.value(query.record().indexOf("nbEnfPers")).toInt());
        ui->nbPersonneSpinBox->setValue(query.value(query.record().indexOf("nbhabPers")).toInt());
        QString sexe=query.value(query.record().indexOf("sexePers")).toString();
        if(sexe=="F"){
            ui->sexeCb->setCurrentIndex(1);
        }else{
            ui->sexeCb->setCurrentIndex(0);
        }
        ui->dateNais->setDate(query.value(query.record().indexOf("datenaisPers")).toDate());
        int id_ec=query.value(query.record().indexOf("idEc")).toInt();
        int id_rev=query.value(query.record().indexOf("idRev")).toInt();
        req="select * from Revenu";
        query.prepare(req);
        if(!query.exec()){
            erreurBdd(query);
        }else{
            QStringList revenus;
            revenus.append("");
            while (query.next()) {
                revenus.append(query.value(1).toString() + " - " + query.value(2).toString());
            }
            ui->trancheRevenusComboBox->addItems(revenus);
        }
        req="select * from Etat_Civil";
        query.prepare(req);
        if(!query.exec()){
            erreurBdd(query);
        }else{
            QStringList Etat_civil;
            Etat_civil.append("");
            while (query.next()) {
                Etat_civil.append(query.value(1).toString());
            }
            ui->etatCivilCb->addItems(Etat_civil);
        }
        ui->etatCivilCb->setCurrentIndex(id_ec);
        ui->trancheRevenusComboBox->setCurrentIndex(id_rev);
    }
}

//fermeture de la page/bdd
void DialogGestionCompte::closePage(){
    this->close();
}

void DialogGestionCompte::on_SubmitButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="Update Personne set datenaisPers=:date, sexePers=:sexe, nbhabPers=:nbhabpers, nbEnfPers=:nbenf, nbAnimPers=:nbanim, idEc=:idEc, idRev=:idRev where identifiantPers=:id";
    query.prepare(req);
    query.bindValue(":id",global_id);
    query.bindValue(":date",ui->dateNais->date().toString("yyyy/MM/dd"));
    if(ui->sexeCb->currentText() == "Femme"){
        query.bindValue(":sexe","F");
    }else{
        query.bindValue(":sexe","H");
    }
    query.bindValue(":nbhabpers",ui->nbPersonneSpinBox->value());
    query.bindValue(":nbenf",ui->nbEnfantSpinBox->value());
    query.bindValue(":nbanim",ui->nbAnimauxSpinBox->value());
    query.bindValue(":idEc",ui->etatCivilCb->currentIndex());
    query.bindValue(":idRev",ui->trancheRevenusComboBox->currentIndex());
    if(!query.exec()){
        erreurBdd(query);
    }else{
        QMessageBox::information(this, this->trUtf8("Inscription validée"),this->trUtf8("Les modifications ont bien été prises en compte ! \n"));
    }
    closePage();
}
