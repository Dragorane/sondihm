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
    int i;
        
    // tranche d’âge moyenne des consommateurs de yaourts anti-cholestérol

    QString req_date = "select julianday('now')";
    query.prepare(req_date);
    if(!query.exec()){
        erreurBdd(query);
        std::cout << "2" << std::endl;
        return;
    }

    query.next();
    float c_date = query.value(0).toFloat();

    QString req_ch = "select AVG(julianday(datenaisPers)) from Personne where idPers in (select idPers from Valeurs where valeurVal > 0 and idChamps = 26)";
	query.prepare(req_ch);
	
	if(!query.exec()){
        erreurBdd(query);
        std::cout << "2" << std::endl;
        return;
	}
	query.next();
    float avg_age = (c_date-query.value(0).toFloat())/365.0;
    qDebug()<<query.value(0).toInt();

	QString choleavg = QString::number(avg_age) + " ans";
	ui->choleavg->setText(choleavg);
	
	// nombre d’enfants moyen parmi les foyers consommateurs de yaourts à boire
	QString req_ki = "select AVG(nbEnfPers) from Personne where idPers in (select idPers from Valeurs where valeurVal > 0 and idChamps = 27)";
	query.prepare(req_ki);
	if(!query.exec()){
        erreurBdd(query);
        std::cout << "3" << std::endl;
        return;
	}
	query.next();
	int avg_enf = query.value(0).toInt();
	
	QString enfavg = QString::number(avg_enf) + " enfants";
	
	ui->enfavg->setText(enfavg);
	
	// nombre de types de yaourts
	QString req_mix = "select count(*) from Champs where idSousChamp = 19";
	query.prepare(req_mix);
    if(!query.exec()){
        erreurBdd(query);
        std::cout << "4" << std::endl;
        return;
	}
	query.next();
	int nb_yaourts = query.value(0).toInt();
	
	float tab_ya[nb_yaourts];
	float tab_aubonlait[nb_yaourts];
	int tranches = 5, j;
	int tab_tranches[tranches];
	
	for(i = 0; i < tranches; i++) {
		tab_tranches[i] = 0;
	}
	
	for(i = 0; i < nb_yaourts; i++) {
		// consommation moyenne de tel ou tel type de yaourt (ex. yaourts aux fruits mixés)
		QString req_y = "select AVG(valeurVal) from Valeurs where idChamps = :id";
		query.prepare(req_y);
		query.bindValue(":id", (20+i));
		if(!query.exec()){
			erreurBdd(query);
			std::cout << "5" << std::endl;
			return;
		}
		query.next();
		tab_ya[i] = query.value(0).toFloat();
		// proportion de yaourts Aubonlait parmi la consommation moyenne de tel type de yaourt
		QString req_aubonlait = "select AVG(valeurVal) from Valeurs where idChamps = :id";
		query.prepare(req_aubonlait);
		query.bindValue(":id", 31+i);
		if(!query.exec()){
			erreurBdd(query);
			std::cout << "6" << std::endl;
			return;
		}
		query.next();
		tab_aubonlait[i] = query.value(0).toFloat();
		for (j = 0; j < 5; j++) {
			// rapport entre les revenus du foyer et la consommation totale de yaourts
			QString req_tranches = "select SUM(valeurVal) from Valeurs where idChamps = :bi and idPers in (select idPers from Personne where idRev = :j)";
			query.prepare(req_tranches);
			query.bindValue(":bi", 20+i);
			query.bindValue(":j", j);
			if(!query.exec()){
				erreurBdd(query);
				std::cout << "7" << std::endl;
				return;
			}
			query.next();
			tab_tranches[j] += query.value(0).toInt();
		}
	}
    QString QS_cnature = QString::fromUtf8("Nature : ") + QString::number(tab_ya[0]);
    QString QS_cmorceaux = QString::fromUtf8("Avec morceaux : ") + QString::number(tab_ya[1]);
    QString QS_cmix = QString::fromUtf8("Mixé/Brassé : ") + QString::number(tab_ya[2]);
    QString QS_carom = QString::fromUtf8("Aromatisé : ") + QString::number(tab_ya[3]);
    QString QS_cbif = QString::fromUtf8("Au bifidus : ") + QString::number(tab_ya[4]);
    QString QS_cfruits = QString::fromUtf8("Aux fruits : ") + QString::number(tab_ya[5]);
    QString QS_cchol = QString::fromUtf8("Anti-cholestérol : ") + QString::number(tab_ya[6]);
    QString QS_cboire = QString::fromUtf8("À boire : ") + QString::number(tab_ya[7]);
    QString QS_calle = QString::fromUtf8("Allégé : ") + QString::number(tab_ya[8]);
	
	ui->cnature->setText(QS_cnature);
	ui->cmorceaux->setText(QS_cmorceaux);
	ui->cmix->setText(QS_cmix);
	ui->carom->setText(QS_carom);
	ui->cbif->setText(QS_cbif);
	ui->cfruits->setText(QS_cfruits);
	ui->cchol->setText(QS_cchol);
	ui->cboire->setText(QS_cboire);
	ui->calle->setText(QS_calle);
	
	QString QS_cnatureau = QString::number(tab_aubonlait[0]) + "%";
	QString QS_cmorceauxau = QString::number(tab_aubonlait[1]) + "%";
	QString QS_cmixau = QString::number(tab_aubonlait[2]) + "%";
	QString QS_caromau = QString::number(tab_aubonlait[3]) + "%";
	QString QS_cbifau = QString::number(tab_aubonlait[4]) + "%";
	QString QS_cfruitsau = QString::number(tab_aubonlait[5]) + "%";
	QString QS_ccholeau = QString::number(tab_aubonlait[6]) + "%";
	QString QS_cboireau = QString::number(tab_aubonlait[7]) + "%";
	QString QS_calleau = QString::number(tab_aubonlait[8]) + "%";
	
	ui->cnatureau->setText(QS_cnatureau);
	ui->cmorceauxau->setText(QS_cmorceauxau);
	ui->cmixau->setText(QS_cmixau);
	ui->caromau->setText(QS_caromau);
	ui->cbifau->setText(QS_cbifau);
	ui->cfruitsau->setText(QS_cfruitsau);
	ui->ccholeau->setText(QS_ccholeau);
	ui->cboireau->setText(QS_cboireau);
	ui->calleau->setText(QS_calleau);
		
	QString QS_t1 = ":                " + QString::number(tab_tranches[0]);
	QString QS_t2 = ":                " + QString::number(tab_tranches[1]);
	QString QS_t3 = ":                " + QString::number(tab_tranches[2]);
	QString QS_t4 = ":                " + QString::number(tab_tranches[3]);
	QString QS_t5 = ":                " + QString::number(tab_tranches[4]);
	
	ui->l1->setText(QS_t1);
	ui->l2->setText(QS_t2);
	ui->l3->setText(QS_t3);
	ui->l4->setText(QS_t4);
	ui->l5->setText(QS_t5);
	
	int m, f;
	
	// plus de femmes consomment des yaourts allégés que d'hommes ?
	
	QString req_m = "select count(*) from Personne where idPers in (select idPers from Valeurs where valeurVal != 0 and idChamps = 28) and sexePers = 'M'";
	query.prepare(req_m);
	if(!query.exec()){
		erreurBdd(query);
		std::cout << "8" << std::endl;
		return;
	}
	query.next();
	m = query.value(0).toInt();
	QString req_f = "select count(*) from Personne where idPers in (select idPers from Valeurs where valeurVal != 0 and idChamps = 28) and sexePers = 'F'";
	query.prepare(req_f);
	if(!query.exec()){
		erreurBdd(query);
		std::cout << "9" << std::endl;
		return;
	}
	query.next();
	f = query.value(0).toInt();
	
	QString femme;
    if ((f == 0) || (m == 0)) femme = QString::fromUtf8("Les femmes consomment ") + QString::number(f) + QString::fromUtf8(" yaourts allégés quand les hommes en consomment ") + QString::number(m) + ".";
    else femme = QString::fromUtf8("Les femmes consomment ") + QString::number((float)f/m) + QString::fromUtf8(" fois ce que les hommes consomment.");
	
	ui->femme->setText(femme);
}

