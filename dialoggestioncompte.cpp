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
    query.bindValue(":id",2093);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        query.next();
        ui->nbAnimauxSpinBox->setValue(query.value(query.record().indexOf("nbAnimPers")).toInt());
        ui->nbEnfantSpinBox->setValue(query.value(query.record().indexOf("nbEnfPers")).toInt());
        ui->nbPersonneSpinBox->setValue(query.value(query.record().indexOf("nbhabPers")).toInt());
        QString sexe=query.value(query.record().indexOf("sexePers")).toString();
        if(sexe=="F"){

        }else{

        }
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
    }
}

//fermeture de la page/bdd
void DialogGestionCompte::closePage(){
    this->close();
}
//qmessagebox pour une erreur de la bdd
void DialogGestionCompte::erreurBdd(QSqlQuery query){
    QSqlError err = query.lastError();
    QMessageBox::critical(0, "Erreur interne à la base de données", err.text());
}
