#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class DialogInscription;
}

class DialogInscription : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInscription(QWidget *parent = 0);
    ~DialogInscription();

private slots:
    void on_CancelButton_clicked();

private:
    Ui::DialogInscription *ui;
    void initchamps();
};

#endif // DIALOGINSCRIPTION_H
