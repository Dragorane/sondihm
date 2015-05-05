#include "dialogformulaire.h"
#include "ui_dialogformulaire.h"

DialogFormulaire::DialogFormulaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogFormulaire)
{
    ui->setupUi(this);
    initForm();
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
        qDebug() << "ca passe ?";
        qDebug()<<global_id_form;
        qDebug() <<query.value(query.record().indexOf("nomForm")).toString();
        qDebug() << "ca passe ?";

        ui->lab_titreform->setText(query.value(query.record().indexOf("nomForm")).toString());
        qDebug() << "ca passe ?";

        initChamps();
    }

}

void DialogFormulaire::initChamps(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Champs where idForm=:id and idSousChamp IS NULL order by ordre";
    query.prepare(req);
    query.bindValue(":id",global_id_form);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        QLineEdit * champ_input;
        QDateEdit * champ_date;
        QSpinBox * champ_spin;
        QComboBox * cbbox;
        while(query.next()){
            QLabel * lab= new QLabel();
            lab->setText(query.value(query.record().indexOf("labChamps")).toString());
            switch (query.value(query.record().indexOf("idTC")).toInt()){
                //input
                case 1 :
                    champ_input = new QLineEdit();
                    champ_input->setObjectName(query.value(query.record().indexOf("idChamps")).toString());
                    ui->formLayout->addRow(lab,champ_input);
                break;
                //dateinput
                case 2 :
                    champ_date = new QDateEdit();
                    champ_date->setObjectName(query.value(query.record().indexOf("idChamps")).toString());
                    ui->formLayout->addRow(lab,champ_date);
                break;
                // spinbox
                case 3 :
                    champ_spin = new QSpinBox();
                    champ_spin->setObjectName(query.value(query.record().indexOf("idChamps")).toString());
                    ui->formLayout->addRow(lab,champ_spin);
                break;
                //radiobox
                case 5 :
                    initSousChamps(query.value(query.record().indexOf("idChamps")).toInt(), lab);

                break;
                //checkbox
                case 6 :

                break;
                //combobox
                case 7 :

                break;
            default:
                break;
            }
        }
    }
}

void DialogFormulaire::initSousChamps(int id,QLabel * lab){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Champs where idForm=:id and idSousChamp=:idsouschamps order by ordre";
    query.prepare(req);
    query.bindValue(":id",global_id_form);
    query.bindValue(":idsouschamps",id);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        QVBoxLayout * vbox;
        QRadioButton * radiobutt;
        vbox = new QVBoxLayout();
        while(query.next()){
            radiobutt= new QRadioButton(query.value(query.record().indexOf("labChamps")).toString());
            radiobutt->setObjectName(query.value(query.record().indexOf("idChamps")).toString());
            vbox->addWidget(radiobutt);
        }
        ui->formLayout->addRow(lab,vbox);
    }
}
