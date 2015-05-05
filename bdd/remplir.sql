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
INSERT into Type_Champs values (4,"doublespinboxe");
INSERT into Type_Champs values (5,"radiobox");
INSERT into Type_Champs values (6,"checkbox");

INSERT into Personne values(0,0000,"","01/01/2001","H",0,0,0,1,1);

INSERT into Formulaire values(0,"Consommation de yaourts du foyer",1,"",1,0);

INSERT into Champs values(1,"Quelles marques de yaourts connaissez vous ?",1,1,NULL,6);
INSERT into Champs values(2,"Nestlé",1,1,1,6);
INSERT into Champs values(3,"Yoplait",1,1,1,6);
INSERT into Champs values(4,"Danone",1,1,1,6);
INSERT into Champs values(5,"Aubonlait",1,1,1,6);
INSERT into Champs values(6,"Activia",1,1,1,6);
INSERT into Champs values(7,"Velouté Fruix",1,1,1,6);
INSERT into Champs values(8,"TailleFine",1,1,1,6);
INSERT into Champs values(9,"Autres",1,1,1,6);

INSERT into Champs values(10,"Quelles marques de yaourts avez vous acheté durant ces 6 derniers mois ?",2,1,NULL,6);
INSERT into Champs values(11,"Nestlé",1,1,10,6);
INSERT into Champs values(12,"Yoplait",1,1,10,6);
INSERT into Champs values(13,"Danone",1,1,10,6);
INSERT into Champs values(14,"Aubonlait",1,1,10,6);
INSERT into Champs values(15,"Activia",1,1,10,6);
INSERT into Champs values(16,"Velouté Fruix",1,1,10,6);
INSERT into Champs values(17,"TailleFine",1,1,10,6);
INSERT into Champs values(18,"Autres",1,1,10,6);

INSERT into Champs values(19,"Combien de yaourt(s) achetez vous par semaine ?",3,1,NULL,3);

