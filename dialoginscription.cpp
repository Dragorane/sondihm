#include "dialoginscription.h"
#include "ui_dialoginscription.h"

DialogInscription::DialogInscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInscription)
{
    ui->setupUi(this);
    initchamps();
}

DialogInscription::~DialogInscription()
{
    delete ui;
}

void DialogInscription::on_CancelButton_clicked()
{
    this->close();
}

void DialogInscription::initchamps(){
    //ajout de données non inclu dans la bdd
    // connexion à la base de donnée
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("ihm.db");
    if (!db.open()) {
        qDebug() << db.lastError().text();

        QMessageBox::critical(0, qApp->tr("Impossible d'ouvrir la base de donnees"),
                              qApp->tr("Impossible d'ouvrir la base de donnees.\n"
    "Ce programme a besoin d'une base de donnée' SQLite support.\n\n"
    "cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
    }else{
        QSqlQuery query(db);
        QString req="select * from Revenu";
        query.prepare(req);
        if(!query.exec()){
            QSqlError err = query.lastError();
            QMessageBox::critical(0, "Erreur sur albums", err.text());
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
            QMessageBox::critical(0, "Erreur sur albums", err.text());
        }else{
            QStringList Etat_civil;
            Etat_civil.append("");
            while (query.next()) {
                Etat_civil.append(query.value(1).toString());
            }
            ui->etatCivilCb->addItems(Etat_civil);
        }
        db.close();
    }
}

void DialogInscription::on_SubmitButton_clicked()
{
   /* QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("ihm.db");
    if (!db.open()) {
        qDebug() << db.lastError().text();

        QMessageBox::critical(0, qApp->tr("Impossible d'ouvrir la base de donnees"),
                              qApp->tr("Impossible d'ouvrir la base de donnees.\n"
    "Ce programme a besoin d'une base de donnée' SQLite support.\n\n"
    "cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
    }else{
        QSqlQuery query(db);
        QString req="INSERT INTO Personne(identifiantPers, datenaisPers, sexePers, nbhabPers, nbEnfPers, nbAnimPers, idEc, idRev) values(:id, )";
        query.prepare(req);

        if(!query.exec()){
            QSqlError err = query.lastError();
            QMessageBox::critical(0, "Erreur sur albums", err.text());
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
            QMessageBox::critical(0, "Erreur sur albums", err.text());
        }else{
            QStringList Etat_civil;
            Etat_civil.append("");
            while (query.next()) {
                Etat_civil.append(query.value(1).toString());
            }
            ui->etatCivilCb->addItems(Etat_civil);
        }
        db.close();
    }*/
}
