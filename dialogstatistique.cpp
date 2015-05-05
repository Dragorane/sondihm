#include "dialogstatistique.h"
#include "ui_dialogstatistique.h"

DialogStatistique::DialogStatistique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogStatistique)
{
    ui->setupUi(this);
    getStats();
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
        std::cout << "1" << std::endl;
        return;
	}
	nb = query.next();
	
	// tranche d’âge moyenne des consommateurs de yaourts anti-cholestérol
	QString req_ch = "select AVG(julianday('now')-julianday(datenaisPers)) from Personne where idPers in (select idPers from Valeurs where valeurVal > 0 and idChamps = 26)";
	query.prepare(req_ch);
	
	if(!query.exec()){
        erreurBdd(query);
        std::cout << "2" << std::endl;
        return;
	}
	int avg_age = query.next()/365;
	
	// nombre d’enfants moyen parmi les foyers consommateurs de yaourts à boire
	QString req_ki = "select AVG(nbEnfPers) from Personne where idPers in (select idPers from Valeurs where valeurVal > 0 and idChamps = 27)";
	query.prepare(req_ki);
	if(!query.exec()){
        erreurBdd(query);
        std::cout << "3" << std::endl;
        return;
	}
	int avg_enf = query.next();
	
	// nombre de types de yaourts
	QString req_mix = "select count(*) from Champs where idSousChamp = 19";
	query.prepare(req_mix);
    if(!query.exec()){
        erreurBdd(query);
        std::cout << "4" << std::endl;
        return;
	}
	int nb_yaourts = query.next();
	std::cout << nb_yaourts << std::endl;
	
	int tab_ya[nb_yaourts];
	int tab_aubonlait[nb_yaourts];
	int tranches = 5, j;
	int tab_tranches[tranches];
	
	for(i = 0; i < tranches; i++) {
		tab_tranches[i] = 0;
	}
	
	for(i = 0; i < nb_yaourts; i++) {
		// consommation moyenne de tel ou tel type de yaourt (ex. yaourts aux fruits mixés)
		QString req_y = "select AVG(valeurVal) from Valeurs where idChamps = :id";
		query.bindValue(":id", 20+i);
		query.prepare(req_y);
		if(!query.exec()){
			erreurBdd(query);
			std::cout << "5" << std::endl;
			return;
		}
		tab_ya[i] = query.next();
		std::cout << tab_ya[i] << std::endl;
		// proportion de yaourts Aubonlait parmi la consommation moyenne de tel type de yaourt
		QString req_aubonlait = "select AVG(valeurVal) from Valeurs where idChamps = :id";
		query.bindValue(":id", 31+i);
		query.prepare(req_y);
		if(!query.exec()){
			erreurBdd(query);
			std::cout << "6" << std::endl;
			return;
		}
		tab_aubonlait[i] = query.next();
		for (j = 0; j < 5; j++) {
			// rapport entre les revenus du foyer et la consommation totale de yaourts
			QString req_tranches = "select SUM(valeurVal) from Valeurs where idChamps = :bi and idPers in (select idPers from Personne where idRev = :j)";
			query.bindValue(":bi", 20+i);
			query.bindValue(":j", j);
			query.prepare(req_tranches);
			if(!query.exec()){
				erreurBdd(query);
				std::cout << "7" << std::endl;
				return;
			}
			tab_tranches[j] += query.next();
		}
	}
	
	QString QS_cnature = "Nature : " + QString::number(tab_ya[0]);
	QString QS_cmorceaux = "Avec morceaux : " + QString::number(tab_ya[1]);
	QString QS_cmix = "Mixé/Brassé : " + QString::number(tab_ya[2]);
	QString QS_carom = "Aromatisé : " + QString::number(tab_ya[3]);
	QString QS_cbif = "Au bifidus : " + QString::number(tab_ya[4]);
	QString QS_cfruits = "Aux fruits : " + QString::number(tab_ya[5]);
	QString QS_cchol = "Anti-cholestérol : " + QString::number(tab_ya[6]);
	QString QS_cboire = "À boire : " + QString::number(tab_ya[7]);
	QString QS_calle = "Allégé : " + QString::number(tab_ya[8]);
	
	ui->cnature->setText(QS_cnature);
	ui->cmorceaux->setText(QS_cmorceaux);
	ui->cmix->setText(QS_cmix);
	ui->carom->setText(QS_carom);
	ui->cbif->setText(QS_cbif);
	ui->cfruits->setText(QS_cfruits);
	ui->cchol->setText(QS_cchol);
	ui->cboire->setText(QS_cboire);
	ui->calle->setText(QS_calle);
	
	int m, f;
	
	// plus de femmes consomment des yaourts allégés que d'hommes ?
	bool fmtm = 0;
	
	QString req_m = "select count(*) from Personne where idPers in (select idPers from Valeurs where valeurVal != 0 and idChamps = 28) and sexePers = 'M'";
	query.prepare(req_m);
	if(!query.exec()){
		erreurBdd(query);
		std::cout << "8" << std::endl;
		return;
	}
	m = query.next();
	QString req_f = "select count(*) from Personne where idPers in (select idPers from Valeurs where valeurVal != 0 and idChamps = 28) and sexePers = 'F'";
	query.prepare(req_f);
	if(!query.exec()){
		erreurBdd(query);
		std::cout << "9" << std::endl;
		return;
	}
	f = query.next();
	
	(f > m) ? fmtm = 1 : fmtm = 0;
	
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

