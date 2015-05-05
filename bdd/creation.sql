DROP TABLE IF EXISTS Etat_Civil ;
CREATE TABLE Etat_Civil (
  idEc  INTEGER PRIMARY KEY,
  libEc VARCHAR(200));

DROP TABLE IF EXISTS Revenu ;
CREATE TABLE Revenu (
  idRev INTEGER PRIMARY KEY, 
  minRev DOUBLE,
  maxRev DOUBLE);

DROP TABLE IF EXISTS Societe ;
CREATE TABLE Societe (
  idSoc INTEGER PRIMARY KEY, 
  nomSoc VARCHAR(200));

DROP TABLE IF EXISTS Type_Champs ;
CREATE TABLE Type_Champs (
  idTC INTEGER PRIMARY KEY, 
  libTC VARCHAR(100));
  
DROP TABLE IF EXISTS Personne;
CREATE TABLE Personne (
  idPers INTEGER PRIMARY KEY, 
  identifiantPers INT,
  mdpPers VARCHAR(50),
  datenaisPers DATE,
  sexePers VARCHAR(2),
  nbhabPers INT,
  nbEnfPers INT,
  nbAnimPers INT,
  idEc INT,
  idRev INT,
  FOREIGN KEY (idEc) REFERENCES Etat_Civil (idEc),
  FOREIGN KEY (idRev) REFERENCES Revenu (idRev));

DROP TABLE IF EXISTS Formulaire ;
CREATE TABLE Formulaire (
  idForm INTEGER PRIMARY KEY, 
  nomForm VARCHAR(200),
  statForm BOOL,
  descForm TEXT,
  idSoc INT NOT NULL,
  idPers INT NOT NULL,
  FOREIGN KEY (idSoc) REFERENCES Societe (idSoc),
  FOREIGN KEY (idPers) REFERENCES Personne (idPers));

DROP TABLE IF EXISTS Champs ; 
CREATE TABLE Champs (
  idChamps INTEGER PRIMARY KEY, 
  labChamps VARCHAR(200),
  ordre INT,
  idForm INT NOT NULL,
  idSousChamp INT,
  idTC INT NOT NULL,
  FOREIGN KEY (idForm) REFERENCES Formulaire (idForm),
  FOREIGN KEY (idSousChamp) REFERENCES Champs (idChamps),
  FOREIGN KEY (idTC) REFERENCES Type_Champs (idTC));  

  DROP TABLE IF EXISTS Valeurs ; 
CREATE TABLE Valeurs (
  idVal INTEGER PRIMARY KEY, 
  contenuVal TEXT,
  valeurVal INT,
  boolval bool,
  idChamps INT NOT NULL,
  idPers INT NOT NULL,
  FOREIGN KEY (idChamps) REFERENCES Champs (idChamps),
  FOREIGN KEY (idPers) REFERENCES Personne (idPers));