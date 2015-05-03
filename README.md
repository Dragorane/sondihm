# sondihm
----------Description des fichiers----------

class mainwindow
Première Dialog de l'application : sélection entre inscription et connexion
mainwindow.cpp : implémentation des fonctions
mainwindow.h : header de la class
mainwindow.ui design de la class

class dialoginscription
formlaire d'inscription d'un nouveau sondé
dialoginscription.cpp : implémentation des fonctions
dialoginscription.h : header de la class
dialoginscription.ui design de la class

class dialogconnexion
formulaire permettant la connexion d'un sondé avec son identifiant
dialogconnexion.cpp : implémentation des fonctions
dialogconnexion.h : header de la class
dialogconnexion.ui design de la class

class dialogaccueil
Dialog de présentation de l'application après la connexion
dialogaccueil.cpp : implémentation des fonctions
dialogaccueil.h : header de la class
dialogaccueil.ui design de la class

class mainformulaire
Dialog affichant dans un tableau les formulaires contenu dans la base de donnée
Permet d'aller à la dialog de réponse d'un formulaire
Permet d'aller à la dialog d'affichage des statistiques
Permet d'aller à la dialog de création d'un nouveau formulaire
mainformulaire.cpp : implémentation des fonctions
mainformulaire.h : header de la class
mainformulaire.ui design de la class

class dialogformulaire
Dialog affichant un formulaire, rempli par un sondé.
dialogformulaire.cpp : implémentation des fonctions
dialogformulaire.h : header de la class
dialogformulaire.ui design de la class

class dialogstatistique
Dialog affichant les statistiques d'un sondage.
dialogstatistique.cpp : implémentation des fonctions
dialogstatistique.h : header de la class
dialogstatistique.ui design de la class

class dialoggestioncompte
Dialog permettant de modifier les informations d'un sonde.
dialoggestioncompte.cpp : implémentation des fonctions
dialoggestioncompte.h : header de la class
dialoggestioncompte.ui design de la class

----------Description de la base de donnée----------
Les fichiers de création de la base de données sont contenus dans le dossier bdd/

Etat civil : table contenant les états civils à afficher dans la combobox. ID et libellé
Etat_Civil (idEc  INTEGER PRIMARY KEY,libEc VARCHAR(200));

Revenu : table contenant les tranches de revenus à afficher dans la combobx. ID, min et max de la tranche
Revenu (idRev INTEGER PRIMARY KEY, minRev DOUBLE,maxRev DOUBLE);

Societe : table contenant l'id et le nom de la société qui demande un sondage
Societe (idSoc INTEGER PRIMARY KEY, nomSoc VARCHAR(200));

Type_Champs : table contenant les différents type de champs qu'un formulaire peut afficher : id et libellé
Type_Champs (idTC INTEGER PRIMARY KEY, libTC VARCHAR(100));

Personne : table contenant les sondés : id dans la table, identifiant de connexion, mot de passe (pas encore utilisé)
                                        date de naissance, sexe (H ou F), le nombre d'habitants dans le foyer, 
                                        le nombre d'enfant dans le foyer, le nombre d'animaux dans le foyer,
                                        une clé étrangère vers l'état civil de la personne (table Etat_civil)
                                        une clé étrangère vers la tranche de revenu de la personne (table Revenu)
Personne (idPers INTEGER PRIMARY KEY, identifiantPers INT, mdpPers VARCHAR(50), datenaisPers DATE,
         sexePers VARCHAR(2), nbhabPers INT, nbEnfPers INT, nbAnimPers INT, idEc INT, idRev INT,
         FOREIGN KEY (idEc) REFERENCES Etat_Civil (idEc), FOREIGN KEY (idRev) REFERENCES Revenu (idRev));

Formulaire : table contenant un formualaire : id, nom du formulaire, stat (bool vrai= stat dispo, false: pas disponible),
                                              clé étrangère vers la société qui demande le sondage,
                                              clé étrangère vers la personne qui créé le formulaire.
Formulaire (idForm INTEGER PRIMARY KEY, nomForm VARCHAR(200), statForm BOOL, idSoc INT NOT NULL, idPers INT NOT NULL,
            FOREIGN KEY (idSoc) REFERENCES Societe (idSoc), FOREIGN KEY (idPers) REFERENCES Personne (idPers));

Champs : table contenant les champs d'un formulaire : id, label du champs, clé étrangère vers le formulaire,
						      clès étrangère vers un autre champs (si il s'agit d'un sous champs, 
						      comme une checkbox),
						      clé étrangère vers le type de champs.
Champs (idChamps INTEGER PRIMARY KEY, labChamps VARCHAR(200), idForm INT NOT NULL, idSousChamp INT,
       idTC INT NOT NULL, FOREIGN KEY (idForm) REFERENCES Formulaire (idForm),
       FOREIGN KEY (idSousChamp) REFERENCES Champs (idChamps), FOREIGN KEY (idTC) REFERENCES Type_Champs (idTC));  

Valeurs : table contenant les réponses d'un sondé à un champs. id, contenuval(si réponse char*), 
								valeurval (si réponse int)
								boolval (si réponse booléenne)
								idChamps :clé étrangère vers le champs
								idPers : clé étrangère vers le sondé
Valeurs (idVal INT INTEGER PRIMARY KEY, contenuVal TEXT, valeurVal INT, boolval bool, idChamps INT NOT NULL,
         idPers INT NOT NULL, FOREIGN KEY (idChamps) REFERENCES Champs (idChamps), FOREIGN KEY (idPers) REFERENCES Personne (idPers));