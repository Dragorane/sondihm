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

void DialogStatistique::getStats() {
    
	QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    int nb, i;
    
    // Nombre de participants au sondage
    QString req = "select count(*) from Valeurs where valeurVal = 0";
    query.prepare(req);
    if(!query.exec()){
        erreurBdd(query);
        return;
	}
	nb = query.next();
	
	// tranche d’âge moyenne des consommateurs de yaourts anti-cholestérol
	QString req_ch = "select AVG(julianday('now')-julianday(datenaisPers)) from Personne where idPers in (select idPers from Valeurs where valeurVal > 0 \
	and idChamps = 26";
	query.prepare(req_ch);
	
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	int avg_age = query.next()/365;
	
	// nombre d’enfants moyen parmi les foyers consommateurs de yaourts à boire
	QString req_ki = "select AVG(nbEnfPers) from Personne where idPers in (select idPers from Valeurs where valeurVal > 0 and idChamps = 27)";
	query.prepare(req_ki);
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	int avg_enf = query.next();
	
	// nombre de types de yaourts
	QString req_mix = "select count(*) from Champs where idSousChamp = 19";
	query.prepare(req_mix);
    if(!query.exec()){
        erreurBdd(query);
        return;
	}
	int nb_yaourts = query.next();
	
	int tab_ya[nb_yaourts];
	int tab_aubonlait[nb_yaourts];
	
	
	for(i = 0; i < nb_yaourts; i++) {
		// consommation moyenne de tel ou tel type de yaourt (ex. yaourts aux fruits mixés)
		QString req_y = "select AVG(valeurVal) from Valeurs where idChamps = :id";
		query.bindValue(":id", 20+i);
		query.prepare(req_y);
		if(!query.exec()){
			erreurBdd(query);
			return;
		}
		tab_ya[i] = query.next();
		// proportion de yaourts Aubonlait parmi la consommation moyenne de tel type de yaourt
		QString req_aubonlait = "select AVG(valeurVal) from Valeurs where idChamps = :id";
		query.bindValue(":id", 31+i);
		query.prepare(req_y);
		if(!query.exec()){
			erreurBdd(query);
			return;
		}
		tab_aubonlait[i] = query.next();
	}
	
	/*QString req_y1 = "select SUM(valeurVal) from Valeurs where idChamps = 20"; // Nature
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y2 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Morceaux
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y3 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Mixés
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y4 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Aromatisés
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y5 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Bifidus
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y6 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Fruits
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y7 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Anti-chol
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y8 = "select SUM(valeurVal) from Valeurs where idChamps = 20";  // Boire
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y9; // Allégé
	if(!query.exec()){
        erreurBdd(query);
        return;
	}
	QString req_y10;
	
	req = */
}

