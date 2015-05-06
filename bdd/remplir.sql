INSERT into Etat_Civil values (1,"Célibataire");
INSERT into Etat_Civil values (2,"Marié(e)");
INSERT into Etat_Civil values (3,"Veuf(ve)");

INSERT into Revenu values (1,0.0,10000.0);
INSERT into Revenu values (2,10000.0,25000.0);
INSERT into Revenu values (3,25000.0,75000.0);
INSERT into Revenu values (4,75000.0,150000.0);
INSERT into Revenu values (5,150000.0,999999.0);

INSERT into Societe values (1,"Aubonlait");

INSERT into Type_Champs values (1,"input");
INSERT into Type_Champs values (2,"dateinput");
INSERT into Type_Champs values (3,"spinbox");
INSERT into Type_Champs values (4,"doublespinbox");
INSERT into Type_Champs values (5,"radiobox");
INSERT into Type_Champs values (6,"checkbox");
INSERT into Type_Champs values (7,"combobox");

INSERT into Personne values(0,0000,"","2001-01-01","H",0,0,0,1,1);

INSERT into Formulaire values(0,"Consommation de yaourts du foyer",1,"",1,0);

INSERT into Champs values(1,"Quelles marques de yaourts connaissez-vous ?",1,0,NULL,6);
INSERT into Champs values(2,"Nestlé",1,0,1,6);
INSERT into Champs values(3,"Yoplait",1,0,1,6);
INSERT into Champs values(4,"Danone",1,0,1,6);
INSERT into Champs values(5,"Aubonlait",1,0,1,6);

INSERT into Champs values(10, "Combien de fois avez-vous acheté des yaourts de chacune de ses marques au cours des 6 derniers mois ?",2,0,NULL,3);
INSERT into Champs values(11,"Nestlé",2,0,10,3);
INSERT into Champs values(12,"Yoplait",2,0,10,3);
INSERT into Champs values(13,"Danone",2,0,10,3);
INSERT into Champs values(14,"Aubonlait",2,0,10,3);

INSERT into Champs values(19, "Combien consommez-vous de yaourts de chaque type par mois ?",3,0,NULL,3);
INSERT into Champs values(20, "Nature", 3, 0, 19, 3);
INSERT into Champs values(21, "Aux fruits avec morceaux", 3, 0, 19, 3);
INSERT into Champs values(22, "Mixés/Brassés", 3, 0, 19, 3);
INSERT into Champs values(23, "Aromatisés", 3, 0, 19, 3);
INSERT into Champs values(24, "Bifidus Nature", 3, 0, 19, 3);
INSERT into Champs values(25, "Aux Fruits", 3, 0, 19, 3);
INSERT into Champs values(26, "Anti-Cholesterol", 3, 0, 19, 3);
INSERT into Champs values(27, "À boire", 3, 0, 19, 3);
INSERT into Champs values(28, "Allégés", 3, 0, 19, 3);

INSERT into Champs values(30, "Quel pourcentage de ceux-ci étaient de marque Aubonlait ?", 4, 0, NULL, 3);
INSERT into Champs values(31, "Nature", 4, 0, 30, 3);
INSERT into Champs values(32, "Aux fruits avec morceaux", 4, 0, 30, 3);
INSERT into Champs values(33, "Mixés/Brassés", 4, 0, 30, 3);
INSERT into Champs values(34, "Aromatisés", 4, 0, 30, 3);
INSERT into Champs values(35, "Bifidus Nature", 4, 0, 30, 3);
INSERT into Champs values(36, "Aux Fruits", 4, 0, 30, 3);
INSERT into Champs values(37, "Anti-Cholesterol", 4, 0, 30, 3);
INSERT into Champs values(38, "À boire", 4, 0, 30, 3);
INSERT into Champs values(39, "Allégés", 4, 0, 30, 3);