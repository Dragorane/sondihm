#include "dialoginscription.h"
#include "ui_dialoginscription.h"

DialogInscription::DialogInscription(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogInscription)
{
	ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ihm.db");
    if (!db.open()) {
        qDebug() << db.lastError().text();

        QMessageBox::critical(0, qApp->tr("Impossible d'ouvrir la base de donnees"),
                qApp->tr("Impossible d'ouvrir la base de donnees.\n"
                    "Ce programme a besoin d'une base de donnee' SQLite support.\n\n"
                    "cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
    }else{
        initchamps();
    }
}

DialogInscription::~DialogInscription()
{
	delete ui;
}

void DialogInscription::on_CancelButton_clicked()
{
    closePage();
}

void DialogInscription::initchamps(){
	//ajout de données non inclu dans la bdd
	// connexion à la base de donnee
		QSqlQuery query(db);
		QString req="select * from Revenu";
		query.prepare(req);
		if(!query.exec()){
			QSqlError err = query.lastError();
			QMessageBox::critical(0, "Erreur base de donnee", err.text());
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
			QSqlError err = query.lastError();
			QMessageBox::critical(0, "Erreur base de donnee", err.text());
		}else{
			QStringList Etat_civil;
			Etat_civil.append("");
			while (query.next()) {
				Etat_civil.append(query.value(1).toString());
			}
			ui->etatCivilCb->addItems(Etat_civil);
		}
}

void DialogInscription::on_SubmitButton_clicked()
{
		QSqlQuery query(db);
        QString req="INSERT INTO Personne(identifiantPers, datenaisPers, sexePers, nbhabPers, nbEnfPers, nbAnimPers, idEc, idRev) values(:id, :date, :sexe, :nbhabpers, :nbenf, :nbanim, :idEc, :idRev)";
		query.prepare(req);
		int id=newIdUser();
		if(id!=0){
			query.bindValue(":id",id);
            qDebug()<<id;
		}
		query.bindValue(":date",ui->dateNais->date().toString("yyyy/MM/dd"));
        qDebug()<<ui->dateNais->date().toString("yyyy/MM/dd");
		if(ui->sexeCb->currentText() == "Femme"){
			query.bindValue(":sexe","F");
            qDebug()<<"F";
		}else{
			query.bindValue(":sexe","H");
            qDebug()<<"H";
		}
		query.bindValue(":nbhabpers",ui->nbPersonneSpinBox->value());
        qDebug()<<ui->nbPersonneSpinBox->value();
		query.bindValue(":nbenf",ui->nbEnfantSpinBox->value());
        qDebug()<<ui->nbEnfantSpinBox->value();
        query.bindValue(":nbanim",ui->nbAnimauxSpinBox->value());

		query.bindValue(":idEc",ui->etatCivilCb->currentIndex());
        qDebug()<<ui->etatCivilCb->currentIndex();
		query.bindValue(":idRev",ui->trancheRevenusComboBox->currentIndex());
        qDebug()<<ui->trancheRevenusComboBox->currentIndex();
		if(!query.exec()){
			qDebug() << db.lastError().text();
			QMessageBox::critical(0, qApp->tr("Erreur lors de l'enregistrement"),
					qApp->tr("Impossible d'enregistrer le nouveau utilisateur.\n"
						"Ce programme a besoin d'une base de donnee' SQLite support.\n\n"
						"cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
		}else{
			QMessageBox::information(this, "Inscription validee",
					"Felicitation,\n\nLe nouveau sonde a bien ete enregistre...\n\n Numero du sonde : #_____ \n\n");
			qDebug()<<id;
        }
    closePage();
}

//fonction generant l'identifiant unique d'un utilisateur
int DialogInscription::newIdUser(){
	int High=9999, Low=1000, id;
    bool verif=false;
    //generation et requete pour verifier si ce n'est pas deja prit
    QSqlQuery query(db);
    QString req="select count(*) from Personne where identifiantPers=:id";
    query.prepare(req);
    while (verif==false){
        id = qrand() % ((High + 1) - Low) + Low;
        query.bindValue(":id",id);
        if(!query.exec()){
            qDebug() << query.lastError();
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

void DialogInscription::closePage(){
    db.close();
    this->close();
}
