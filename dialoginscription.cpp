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
        qDebug() << "Erreur : ";

        QMessageBox::critical(0, qApp->tr("Impossible d'ouvrir la base de donnees"),
                              qApp->tr("Impossible d'ouvrir la base de donnees.\n"
    "Ce programme a besoin d'une base de donnée' SQLite support.\n\n"
    "cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
    }else{
        qDebug() << "Connected";
        QSqlQuery query;
        query.prepare("SELECT * FROM Revenu");
        query.exec();
        qDebug() << "toujours Connected ?";

        while (query.next()) {
            qDebug() << "Connected";
            qDebug() << query.value(1).toString();
        }
    }
}
