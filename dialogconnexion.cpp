#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"
#include "dialogaccueil.h"

DialogConnexion::DialogConnexion(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogConnexion)
{
	ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
	delete ui;
}

void DialogConnexion::on_CancelButton_clicked()
{
	this->close();
}

void DialogConnexion::on_SubmitButton_clicked() {

	int tmp_id = ui->idLine->text().toInt();
	QSqlDatabase db = QSqlDatabase::database();
	
	QSqlQuery query(db);
	QString req="select count(*) from Personne where identifiantPers=:id";

	query.prepare(req);
	query.bindValue(":id", tmp_id);
	
	if (!query.exec()) {
		erreurRequete();
	}
	else {
		query.next();
		if(query.value(0).toInt() == 0){
			erreurId();
			ui->idLine->repaint();
		}
		else if(query.value(0).toInt() == 1) {
			global_id = tmp_id;
			DialogAccueil *dialog=new DialogAccueil;
			dialog->show();
			this->close();
		}
	}
}
