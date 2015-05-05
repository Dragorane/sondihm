#include "dialogstatistique.h"
#include "ui_dialogstatistique.h"

DialogStatistique::DialogStatistique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogStatistique)
{
    ui->setupUi(this);
}

DialogStatistique::~DialogStatistique()
{
    delete ui;
}

DialogStatistique::getStats() {
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
        QCheckBox * checkbox;
        vbox = new QVBoxLayout();
        while(query.next()){
            switch (query.value(query.record().indexOf("idTC")).toInt()){
                //radiobox
                case 5 :
                    radiobutt= new QRadioButton(query.value(query.record().indexOf("labChamps")).toString());
                    radiobutt->setObjectName(query.value(query.record().indexOf("idChamps")).toString());
                    vbox->addWidget(radiobutt);
                break;
                //checkbox
                case 6 :
                    checkbox = new QCheckBox(query.value(query.record().indexOf("labChamps")).toString());
                    checkbox->setObjectName(query.value(query.record().indexOf("idChamps")).toString());
                    vbox->addWidget(checkbox);
                break;
                default:
                break;
            }
        }
        ui->formLayout->addRow(lab,vbox);
    }
    
	QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    int nb, avg_age;
    QString req = "select count(*) from Valeurs where valeurVal = 0";
    query.prepare(req);
    if(!query.exec()){
        erreurBdd(query);
        return;
	}
	nb = query.next();
	QString req_ch = "select AVG(julianday('now')-julianday(datenaisPers)) from Personne where idPers in (select idPers from Valeurs where valeurVal = 0 \
	and idChamps = 17";
	query.prepare(req_ch);
	
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	
	int avg_age = query.next()/365;
	
	QString req_ki = "select AVG(nbEnfPers) from Personne where idPers in (select idPers from Valeurs where valeurVal = 0 and idChamps = 13)";
	
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	
	int avg_enf = query.next();
	
	QString req_
    if(!query.exec()){
        erreurBdd(query);
        return;
	}
	for(i = 0; i < nb; i++) {
		
	}
	req = 
}

