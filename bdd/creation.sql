DROP TABLE IF EXISTS Etat_Civil ;
CREATE TABLE Etat_Civil (
  idEc INT  AUTO_INCREMENT NOT NULL,
  libEc VARCHAR(200),
  PRIMARY KEY (idEc));

DROP TABLE IF EXISTS Revenu ;
CREATE TABLE Revenu (
  idRev INT  AUTO_INCREMENT NOT NULL,
  minRev DOUBLE,
  maxRev DOUBLE,
  PRIMARY KEY (idRev));

DROP TABLE IF EXISTS Societe ;
CREATE TABLE Societe (
  idSoc INT  AUTO_INCREMENT NOT NULL,
  nomSoc VARCHAR(200),
  PRIMARY KEY (idSoc));

DROP TABLE IF EXISTS Type_Champs ;
CREATE TABLE Type_Champs (
  idTC INT  AUTO_INCREMENT NOT NULL,
  libTC VARCHAR(100),
  PRIMARY KEY (idTC));
  
DROP TABLE IF EXISTS Personne;
CREATE TABLE Personne (
  idPers INT  AUTO_INCREMENT NOT NULL, 
  identifiantPers INT,
  mdpPers VARCHAR(50),
  datenaisPers DATE,
  sexePers VARCHAR(2),
  nbhabPers INT,
  nbEnfPers INT,
  nbAnimPers INT,
  idEc INT,
  idRev INT,
  PRIMARY KEY (idPers),
  FOREIGN KEY (idEc) REFERENCES Etat_Civil (idEc),
  FOREIGN KEY (idRev) REFERENCES Revenu (idRev));

DROP TABLE IF EXISTS Formulaire ;
CREATE TABLE Formulaire (
  idForm INT  AUTO_INCREMENT NOT NULL,
  nomForm VARCHAR(200),
  statForm BOOL,
  idSoc INT NOT NULL,
  idPers INT NOT NULL,
  PRIMARY KEY (idForm),
  FOREIGN KEY (idSoc) REFERENCES Societe (idSoc),
  FOREIGN KEY (idPers) REFERENCES Personne (idPers));

DROP TABLE IF EXISTS Champs ; 
CREATE TABLE Champs (
  idChamps INT  AUTO_INCREMENT NOT NULL,
  labChamps VARCHAR(200),
  idForm INT NOT NULL,
  idSousChamp INT,
  idTC INT NOT NULL,
  PRIMARY KEY (idChamps),
  FOREIGN KEY (idForm) REFERENCES Formulaire (idForm),
  FOREIGN KEY (idSousChamp) REFERENCES Champs (idChamps),
  FOREIGN KEY (idTC) REFERENCES Type_Champs (idTC));  

DROP TABLE IF EXISTS Valeurs ; 
CREATE TABLE Valeurs (
  idVal INT  AUTO_INCREMENT NOT NULL,
  contenuVal TEXT,
  valeurVal INT,
  boolval bool,
  idChamps INT NOT NULL,
  idPers INT NOT NULL,
  PRIMARY KEY (idVal),
  FOREIGN KEY (idChamps) REFERENCES Champs (idChamps)
  FOREIGN KEY (idPers) REFERENCES Personne (idPers));