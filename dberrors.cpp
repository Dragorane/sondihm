#include "dberrors.h"

//qmessagebox pour une erreur de la bdd
void erreurBdd(QSqlQuery query) {
    QSqlError err = query.lastError();
    QMessageBox::critical(0, "Erreur interne à la base de données.", err.text());
}

//qmessagebox pour une erreur d'une requete vers la bdd
void erreurRequete() {
    QMessageBox::critical(0, qApp->trUtf8("Erreur lors de la requête."),
            qApp->trUtf8("Impossible de faire la requête vers la base de données."), QMessageBox::Cancel);
}

//qmessagebox pour utilisation d'un id invalide
void erreurId() {
    QMessageBox::critical(0, qApp->trUtf8("Identifiant de connexion invalide."),
            qApp->trUtf8("Veuillez saisir un identifiant de connexion valide."), QMessageBox::Cancel);
}
