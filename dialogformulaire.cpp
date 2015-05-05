#include "dialogformulaire.h"
#include "ui_dialogformulaire.h"

DialogFormulaire::DialogFormulaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogFormulaire)
{
    ui->setupUi(this);
}

DialogFormulaire::~DialogFormulaire()
{
    delete ui;
}

void DialogFormulaire::initForm(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Formulaire where idForm=:id";
    query.prepare(req);
    query.bindValue(":id",global_id_form);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        query.next();
        ui->lab_titreform->setText(query.value(query.record().indexOf("nomForm")).toString());
        initChamps();
    }

}

void DialogFormulaire::initChamps(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Champs where idForm=:id order by ordre";
    query.prepare(req);
    query.bindValue(":id",global_id_form);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        while(query.next()){
            QString lab=(query.value(query.record().indexOf("labChamps")).toString());
         /*   switch (query.value(query.record().indexOf("idTC")).toInt()){
                //input
                case 1 :
                    //champ QTextEdit();
                break;
                //dateinput
                case 2 :
                    //champ QDateEdit();
                break;
                // spinbox
                case 3 :
                    //champ QSpinBox();
                break;
                //radiobox
                case 4 :

                break;
                //checkbox
                case 5 :

                break;
            }*/

            //ui->formLayout->addRow(lab,champ);
        }
    }
}

void DialogFormulaire::initSousChamps(){

}
