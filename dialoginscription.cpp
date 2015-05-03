#include "dialoginscription.h"
#include "ui_dialoginscription.h"

DialogInscription::DialogInscription(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogInscription)
{
	ui->setupUi(this);
	db = QSqlDatabase::database();
	initchamps();
}

DialogInscription::~DialogInscription()
{
	delete ui;
}

void DialogInscription::on_CancelButton_clicked()
{
	closePage();
}

//initialisation des champs du formulaire avec la bdd
void DialogInscription::initchamps(){
	QSqlQuery query(db);
	QString req="select * from Revenu";
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

//ajout d'un sondé à la base de donnée
void DialogInscription::on_SubmitButton_clicked()
{
	QSqlQuery query(db);
	QString req="INSERT INTO Personne(identifiantPers, datenaisPers, sexePers, nbhabPers, nbEnfPers, nbAnimPers, idEc, idRev) values(:id, :date, :sexe, :nbhabpers, :nbenf, :nbanim, :idEc, :idRev)";
	query.prepare(req);
	int id=newIdUser();
	if(id!=0){
		query.bindValue(":id",id);
	}
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
        char message[200]="Félicitations,\n\nLe nouveau sondé a bien été enregistré.\n\nNuméro du sondé : #";
        char idchar[10];
        global_id = id;
        sprintf(idchar,"%d", id);
        strcat(idchar,"\n");
        strcat(message,idchar);
        QMessageBox::information(this, this->trUtf8("Inscription validée"),this->trUtf8(message));
	}
	closePage();
}

//fonction generant l'identifiant unique d'un utilisateur
int DialogInscription::newIdUser(){
	int High=9999, Low=1000, id;
	bool verif=false;
	QSqlQuery query(db);
	QString req="select count(*) from Personne where identifiantPers=:id";
	query.prepare(req);
	while (verif==false){
		id = qrand() % ((High + 1) - Low) + Low;
		query.bindValue(":id",id);
		if(!query.exec()){
            erreurRequete();
            verif=true;
			id=0;
		}else{
			query.next();
			if(0==query.value(0).toInt()){
				verif=true;
			}
		}
	}
	return id;
}

//fermeture de la page/bdd
void DialogInscription::closePage(){
	db.close();
	this->close();
}
