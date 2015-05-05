#include "dialogcreateform.h"
#include "ui_dialogcreateform.h"

DialogCreateForm::DialogCreateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateForm)
{
    ui->setupUi(this);
    initType();
}

DialogCreateForm::~DialogCreateForm()
{
    delete ui;
}

void DialogCreateForm::validNewForm(){

}

void DialogCreateForm::initType(){
    QComboBox * lestypes;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req="select * from Type_Champs";
    query.prepare(req);
    if(!query.exec()){
        erreurBdd(query);
    }else{
        QStringList types_bd, types_bd2;
        while (query.next()) {
            types_bd.append(query.value(1).toString());
        }
        int i;
        types_bd2=types_bd;
        for(i=0;i<1000;i++){
            types_bd=types_bd2;
            lestypes = new QComboBox();
            lestypes->addItems(types_bd);
            ui->tableWidget->setCellWidget(1,1,lestypes);
        }
    }
}
