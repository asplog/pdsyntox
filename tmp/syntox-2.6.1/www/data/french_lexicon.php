<?php

$lx='

IDENTITY constantNoun;
IDENTITY time;
IDENTITY name;
IDENTITY surname;
IDENTITY emailTo;
IDENTITY num;

&quot;M.&quot;	civ[civ:important, gender:ms, number:sg];
&quot;MM.&quot;	civ[civ:important, gender:ms, number:pl];
&quot;Mme.&quot;	civ[civ:important, gender:fm, number:sg];
&quot;Mmes.&quot;	civ[civ:important, gender:fm, number:pl];
&quot;&quot;	civ[civ:familiar];

&quot;&\epsilon;&quot; empty [];

&quot;.&quot;	dot [];
&quot;,&quot;	comma [];
&quot;par conséquent&quot;	parConséquent [];
&quot;cependant&quot;	cependant [];
&quot;si cependant&quot;	siCependant [];
&quot;alors&quot;	alors [];
&quot;merci de&quot;	merciDe [];
été été[];

monsieur	appel[gender:ms, number:sg, level:normal];
messieurs	appel[gender:ms, number:pl, level:normal];
madame	appel[gender:fm, number:sg, level:normal];
mesdames	appel[gender:fm, number:sg, level:normal];

&quot;madame, monsieur&quot;	appel[gender:ms, number:sg, level:polite];
&quot;chers messieurs&quot;	appel[gender:ms, number:pl, level:polite];
&quot;chère madame&quot;	appel[gender:fm, number:sg, level:polite];
&quot;chères mesdames&quot;	appel[gender:fm, number:sg, level:polite];

cordialement	mailSignature[level:normal];
&quot;très cordialement&quot;	mailSignature[level:polite];

je	cln [PRED:pro, number:sg, person:1];
tu	cln [PRED:pro, number:sg, person:2];
il	cln [PRED:pro, number:sg, person:3, gender:ms];
elle	cln [PRED:pro, number:sg, person:3, gender:fm]
	|pro[PRED:pro, number:sg, person:3, gender:fm];
nous	cln [PRED:pro, number:pl, person:1]
	|pro [PRED:pro, number:pl, person:1];
vous	cln [PRED:pro, number:pl, person:2]
	|pro [PRED:pro, number:pl, person:2];
ils	cln [PRED:pro, number:pl, person:3, gender:ms];
elles	cln [PRED:pro, number:pl, person:3, gender:fm]
	|pro [PRED:pro, number:pl, person:3, gender:fm];

moi	pro[PRED:pro, number:sg, person:1];
toi	pro[PRED:pro, number:sg, person:2];
eux	pro[PRED:pro, number:pl, person:3, gender:ms];

me	cla [PRED:pro, number:sg, person:1]
	|cld [PRED:pro, number:sg, person:1];

te	cla [PRED:pro, number:sg, person:2]
	|cld [PRED:pro, number:sg, person:2];

le	cla [PRED:pro, gender:ms, number:sg, person:3]
	|det [number:sg, gender:ms, def:+, dem:-, poss:-, part:-];

la	cla [PRED:pro, gender:fm, number:sg, person:3]
	|det [number:sg, gender:fm, def:+, dem:-, poss:-, part:-];

les	cla [PRED:pro, number:pl, person:3]
	|det [number:pl, def:+, dem:-, poss:-, part:-];

lui	cld [PRED:pro, number:sg, person:3]
	|pro[PRED:pro, number:sg, person:3, gender:ms];

nous	cla [PRED:pro, number:pl, person:1]
	|cld [PRED:pro, number:pl, person:1];
vous	cla [PRED:pro, number:pl, person:2]
	|cld [PRED:pro, number:pl, person:2];
leur	cld [PRED:pro, number:pl, person:3]
	|det [number:sg, def:-, poss:+, dem:-, personposs:3, numberposs:pl, part:-];

un	det [number:sg, gender:ms, def:-, dem:-, poss:-, part:-];
une	det [number:sg, gender:fm, def:-, dem:-, poss:-, part:-];
des	det [number:pl, def:-, dem:-, poss:-, part:-];

mon	det [number:sg, gender:ms, def:-, poss:+, dem:-, personposs:1, numberposs:sg, part:-];
ma	det [number:sg, gender:fm, def:-, poss:+, dem:-, personposs:1, numberposs:sg, part:-];
mes	det [number:pl, def:-, poss:+, dem:-, personposs:1, numberposs:sg, part:-];
ton	det [number:sg, gender:ms, def:-, poss:+, dem:-, personposs:2, numberposs:sg, part:-];
ta	det [number:sg, gender:fm, def:-, poss:+, dem:-, personposs:2, numberposs:sg, part:-];
tes	det [number:pl, def:-, poss:+, dem:-, personposs:2, numberposs:sg, part:-];
son	det [number:sg, gender:ms, def:-, poss:+, dem:-, personposs:3, numberposs:sg, part:-];
sa	det [number:sg, gender:fm, def:-, poss:+, dem:-, personposs:3, numberposs:sg, part:-];
ses	det [number:pl, def:-, poss:+, dem:-, personposs:3, numberposs:sg, part:-];
notre	det [number:sg, def:-, poss:+, dem:-, personposs:1, numberposs:pl, part:-];
nos	det [number:pl, def:-, poss:+, dem:-, personposs:1, numberposs:pl, part:-];
votre	det [number:sg, def:-, poss:+, dem:-, personposs:2, numberposs:pl, part:-];
vos	det [number:pl, def:-, poss:+, dem:-, personposs:2, numberposs:pl, part:-];
leurs	det [number:pl, def:-, poss:+, dem:-, personposs:3, numberposs:pl, part:-];

ce	det [number:sg, gender:ms, def:-, poss:-, dem:+, part:-];
ces	det [number:pl, def:-, poss:-, dem:+, part:-];
cette	det [number:sg, gender:fm, def:-, poss:-, dem:+, part:-];

&quot;de la&quot;	det [number:sg, gender:fm, def:-, poss:-, dem:-, part:+];
du	det [number:sg, gender:ms, def:-, poss:-, dem:-, part:+];
des	det [number:pl, def:-, dem:-, poss:-];

&quot;arrêt de bus&quot;	nc[PRED:bus_stop, gender:ms, number:sg, anim:no];
&quot;arrêts de bus&quot;	nc[PRED:bus_stop, gender:ms, number:pl, anim:no];
&quot;conducteur de bus&quot;	nc[PRED:bus_rider, gender:ms, number:sg, anim:yes];
&quot;conducteurs de bus&quot;	nc[PRED:bus_rider, gender:ms, number:pl, anim:yes];
&quot;conductrice de bus&quot;	nc[PRED:bus_rider, gender:fm, number:sg, anim:yes];
&quot;conductrices de bus&quot;	nc[PRED:bus_rider, gender:fm, number:pl, anim:yes];

crémier	nc [PRED:creamer, gender:ms, number:sg, anim:yes];
crémiers	nc [PRED:creamer, gender:ms, number:pl, anim:yes];
crémière	nc [PRED:creamer, gender:fm, number:sg, anim:yes];
crémières	nc [PRED:creamer, gender:fm, number:pl, anim:yes];

chat  nc [PRED:cat, number:sg, gender:ms, anim:yes];
chats  nc [PRED:cat, number:pl, gender:ms, anim:yes];

chien  nc [PRED:dog, number:sg, gender:ms, anim:yes];
chiens  nc [PRED:dog, number:pl, gender:ms, anim:yes];

vélo  nc [PRED:bike, number:sg, gender:ms, anim:no];
vélos  nc [PRED:bike, number:pl, gender:ms, anim:no];

voiture  nc [PRED:car, number:sg, gender:fm, anim:no];
voitures  nc [PRED:car, number:pl, gender:fm, anim:no];

poisson  nc [PRED:fish, number:sg, gender:ms, anim:yes];
poissons  nc [PRED:fish, number:pl, gender:ms, anim:yes];

truite  nc [PRED:trout, number:sg, gender:fm, anim:yes];
truites  nc [PRED:trout, number:pl, gender:fm, anim:yes];

&quot;saumon entier&quot;  nc [PRED:whole-salmon, number:sg, gender:ms, den:+, anim:no]|
	nc [PRED:salmon, number:sg, gender:ms, anim:no];
&quot;saumons entiers&quot;  nc [PRED:whole-salmon, number:pl, gender:ms, den:+, anim:no];

&quot;pavé de saumon&quot;  nc [PRED:salmon-steak, number:sg, gender:ms, anim:no];
&quot;pavés de saumon&quot;  nc [PRED:salmon-steak, number:pl, gender:ms, anim:no];

courrier  nc [PRED:mail, number:sg, gender:ms, anim:no];
courriers  nc [PRED:mail, number:pl, gender:ms, anim:no];

chambre  nc [PRED:room, number:sg, gender:fm, anim:no];
chambre  nc [PRED:room, number:pl, gender:fm, anim:no];

&quot;salle de réunion&quot;  nc [PRED:meeting-room, number:sg, gender:fm, anim:no];
&quot;salles de réunion&quot;  nc [PRED:meeting-room, number:pl, gender:fm, anim:no];

&quot;courrier électronique&quot;  nc [PRED:email, number:sg, gender:ms, anim:no];
&quot;courriers électroniques&quot;  nc [PRED:email, number:pl, gender:ms, anim:no];

&quot;petit déjeuner&quot;  nc [PRED:breakfast, number:sg, gender:ms, anim:no];
&quot;petits déjeuner&quot;  nc [PRED:breakfast, number:pl, gender:ms, anim:no];

déjeuner  nc [PRED:lunch, gender:ms, anim:no];

dinner  nc [PRED:dinner, gender:ms, anim:no];

séjour  nc [PRED:journey, number:sg, gender:ms, anim:no];
séjours  nc [PRED:journey, number:pl, gender:ms, anim:no];

taxi  nc [PRED:taxi, number:sg, gender:ms, anim:no];
taxis  nc [PRED:taxi, number:pl, gender:ms, anim:no];

moto  nc [PRED:motorcycle, number:sg, gender:fm, anim:no];
motos  nc [PRED:motorcycle, number:pl, gender:fm, anim:no];

rue  nc [PRED:street, number:sg, gender:fm, anim:no];
rues  nc [PRED:street, number:pl, gender:fm, anim:no];

camion  nc [PRED:truck, number:sg, gender:ms, anim:no];
camions  nc [PRED:truck, number:pl, gender:ms, anim:no];

train  nc [PRED:train, number:sg, gender:ms, anim:no];
trains  nc [PRED:train, number:pl, gender:ms, anim:no];

avion  nc [PRED:airplane, number:sg, gender:ms, anim:no];
avions  nc [PRED:airplane, number:pl, gender:ms, anim:no];

hélicoptère  nc [PRED:helicopter, number:sg, gender:ms, anim:no];
hélicoptères  nc [PRED:helicopter, number:pl, gender:ms, anim:no];

aéroport  nc [PRED:airport, number:sg, gender:ms, anim:no];
aéroports  nc [PRED:airport, number:pl, gender:ms, anim:no];

port  nc [PRED:port, number:sg, gender:ms, anim:no];
ports  nc [PRED:port, number:pl, gender:ms, anim:no];

&quot;station de métro&quot;  nc [PRED:subway_station, number:sg, gender:fm, anim:no];
&quot;stations de métro&quot;  nc [PRED:subway_station, number:pl, gender:fm, anim:no];

métro  nc [PRED:subway, number:sg, gender:ms, anim:no];
métros  nc [PRED:subway, number:pl, gender:ms, anim:no];

bus  nc [PRED:bus, gender:ms, anim:no];

vélo  nc [PRED:bicycle, number:sg, gender:ms, anim:no];
vélos  nc [PRED:bicycle, number:pl, gender:ms, anim:no];

suis	auxEA [aux:être, diathesis:passive, finite:+, mood:indicative, tense:present, subj:[person:1, number:sg]];
es	auxEA [aux:être, diathesis:passive, finite:+, mood:indicative, tense:present, subj:[person:2, number:sg]];
est	auxEA [aux:être, diathesis:passive, finite:+, mood:indicative, tense:present, subj:[person:3, number:sg]];
sommes	auxEA [aux:être, diathesis:passive, finite:+, mood:indicative, tense:present, subj:[person:1, number:pl]];
êtes	auxEA [aux:être, diathesis:passive, finite:+, mood:indicative, tense:present, subj:[person:2, number:pl]];
sont	auxEA [aux:être, diathesis:passive, finite:+, mood:indicative, tense:present, subj:[person:3, number:pl]];

suis auxEA [aux:être, diathesis:active, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:1, number:sg]];
es auxEA [aux:être, diathesis:active, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:2, number:sg]];
est	auxEA [aux:être, diathesis:active, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:3, number:sg]];
sommes auxEA [aux:être, diathesis:active, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:1, number:pl]];
êtes auxEA [aux:être, diathesis:active, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:2, number:pl]];
sont auxEA [aux:être, diathesis:active, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:3, number:pl]];

ai auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:1, number:sg]];
as auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:2, number:sg]];
a	auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:3, number:sg]];
avons auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:1, number:pl]];
avez auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:2, number:pl]];
ont auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:accomplished, subj:[person:3, number:pl]];

avais auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:pastaccomplished, subj:[person:1|2, number:sg]];
avait auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:pastaccomplished, subj:[person:3, number:sg]];
avions auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:pastaccomplished, subj:[person:1, number:pl]];
aviez auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:pastaccomplished, subj:[person:2, number:pl]];
avaient auxEA [aux:avoir, finite:+, mood:indicative, tense:past, aspect:pastaccomplished, subj:[person:3, number:pl]];

aurais auxEA [aux:avoir, finite:+, mood:conditional, tense:past, subj:[person:1|2, number:sg]];
aurait auxEA [aux:avoir, finite:+, mood:conditional, tense:past, subj:[person:3, number:sg]];
aurions auxEA [aux:avoir, finite:+, mood:conditional, tense:past, subj:[person:1, number:pl]];
auriez auxEA [aux:avoir, finite:+, mood:conditional, tense:past, subj:[person:2, number:pl]];
auraient auxEA [aux:avoir, finite:+, mood:conditional, tense:past, subj:[person:3, number:pl]];

aurai auxEA [aux:avoir, finite:+, mood:indicative, tense:future, aspect:accomplished, subj:[person:1, number:sg]];
auras auxEA [aux:avoir, finite:+, mood:indicative, tense:future, aspect:accomplished, subj:[person:2, number:sg]];
aura auxEA [aux:avoir, finite:+, mood:indicative, tense:future, aspect:accomplished, subj:[person:3, number:sg]];
aurons auxEA [aux:avoir, finite:+, mood:indicative, tense:future, aspect:accomplished, subj:[person:1, number:pl]];
aurez auxEA [aux:avoir, finite:+, mood:indicative, tense:future, aspect:accomplished, subj:[person:2, number:pl]];
auront auxEA [aux:avoir, finite:+, mood:indicative, tense:future, aspect:accomplished, subj:[person:3, number:pl]];

aie auxEA [aux:avoir, finite:+, mood:subjunctive, tense:past, subj:[person:1, number:sg]];
aies auxEA [aux:avoir, finite:+, mood:subjunctive, tense:past, subj:[person:2, number:sg]];
ait auxEA [aux:avoir, finite:+, mood:subjunctive, tense:past, subj:[person:3, number:sg]];
ayons auxEA [aux:avoir, finite:+, mood:subjunctive, tense:past, subj:[person:1, number:pl]];
ayez auxEA [aux:avoir, finite:+, mood:subjunctive, tense:past, subj:[person:2, number:pl]];
aient auxEA [aux:avoir, finite:+, mood:subjunctive, tense:past, subj:[person:3, number:pl]];

vais auxV [aux:aller, finite:+, mood:indicative, tense:future, aspect:nearfuture, subj:[person:1, number:sg]];
vas auxV [aux:aller, finite:+, mood:indicative, tense:future, aspect:nearfuture, subj:[person:2, number:sg]];
va auxV [aux:aller, finite:+, mood:indicative, tense:future, aspect:nearfuture, subj:[person:3, number:sg]];
allonss auxV [aux:aller, finite:+, mood:indicative, tense:future, aspect:nearfuture, subj:[person:1, number:pl]];
allez auxV [aux:aller, finite:+, mood:indicative, tense:future, aspect:nearfuture, subj:[person:2, number:pl]];
vont auxV [aux:aller, finite:+, mood:indicative, tense:future, aspect:nearfuture, subj:[person:3, number:pl]];

cherche v[PRED:to-look-for, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
cherches v[PRED:to-look-for, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
cherchons v[PRED:to-look-for, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
cherchez v[PRED:to-look-for, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
cherchent v[PRED:to-look-for, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

cherchais v[PRED:to-look-for, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
cherchait v[PRED:to-look-for, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
cherchions v[PRED:to-look-for, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
	|v[PRED:to-look-for, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
cherchiez v[PRED:to-look-for, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
	|v[PRED:to-look-for, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
cherchaient v[PRED:to-look-for, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

chercherai v[PRED:to-look-for, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
chercheras v[PRED:to-look-for, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
cherchera v[PRED:to-look-for, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
chercherons v[PRED:to-look-for, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
chercherez v[PRED:to-look-for, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
chercheront v[PRED:to-look-for, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

cherché v[PRED:to-look-for, aux:avoir, pastp:+, gender:ms, number:sg];
cherchés v[PRED:to-look-for, aux:avoir, pastp:+, gender:ms, number:pl];
cherchée v[PRED:to-look-for, aux:avoir, pastp:+, gender:fm, number:sg];
cherchées v[PRED:to-look-for, aux:avoir, pastp:+, gender:fm, number:pl];

chercher v[PRED:to-look-for, aux:aller, pastp:-, finite:-];

commande v[PRED:to-order, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
commandes v[PRED:to-order, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
commandons v[PRED:to-order, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
commandez v[PRED:to-order, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
commandent v[PRED:to-order, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

commandais v[PRED:to-order, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
commandait v[PRED:to-order, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
commandions v[PRED:to-order, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
	|v[PRED:to-order, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
commandiez v[PRED:to-order, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
	|v[PRED:to-order, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
commandaient v[PRED:to-order, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

commanderai v[PRED:to-order, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
commanderas v[PRED:to-order, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
commandera v[PRED:to-order, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
commanderons v[PRED:to-order, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
commanderez v[PRED:to-order, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
commanderont v[PRED:to-order, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

commandé v[PRED:to-order, aux:avoir, pastp:+, gender:ms, number:sg];
commandés v[PRED:to-order, aux:avoir, pastp:+, gender:ms, number:pl];
commandée v[PRED:to-order, aux:avoir, pastp:+, gender:fm, number:sg];
commandées v[PRED:to-order, aux:avoir, pastp:+, gender:fm, number:pl];

commander v[PRED:to-order, aux:aller, finite:-];

rembourse v[PRED:to-pay-off, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
rembourses v[PRED:to-pay-off, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
remboursons v[PRED:to-pay-off, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
remboursez v[PRED:to-pay-off, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
remboursent v[PRED:to-pay-off, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

remboursais v[PRED:to-pay-off, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
remboursait v[PRED:to-pay-off, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
remboursions v[PRED:to-pay-off, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-pay-off, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
remboursiez v[PRED:to-pay-off, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-pay-off, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
remboursaient v[PRED:to-pay-off, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

rembourserai v[PRED:to-pay-off, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
rembourseras v[PRED:to-pay-off, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
remboursera v[PRED:to-pay-off, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
rembourserons v[PRED:to-pay-off, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
rembourserez v[PRED:to-pay-off, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
rembourseront v[PRED:to-pay-off, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

remboursé v[PRED:to-pay-off, aux:avoir, pastp:+, gender:ms, number:sg];
remboursés v[PRED:to-pay-off, aux:avoir, pastp:+, gender:ms, number:pl];
remboursée v[PRED:to-pay-off, aux:avoir, pastp:+, gender:fm, number:sg];
remboursées v[PRED:to-pay-off, aux:avoir, pastp:+, gender:fm, number:pl];

rembourser v[PRED:to-pay-off, aux:aller, pastp:-, finite:-];

loue v[PRED:to-rent, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
loues v[PRED:to-rent, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
louons v[PRED:to-rent, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
louez v[PRED:to-rent, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
louent v[PRED:to-rent, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

louais v[PRED:to-rent, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
louait v[PRED:to-rent, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
louions v[PRED:to-rent, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-rent, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
louiez v[PRED:to-rent, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-rent, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
louaient v[PRED:to-rent, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

louerai v[PRED:to-rent, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
loueras v[PRED:to-rent, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
louera v[PRED:to-rent, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
louerons v[PRED:to-rent, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
louerez v[PRED:to-rent, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
loueront v[PRED:to-rent, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

loué v[PRED:to-rent, aux:avoir, pastp:+, gender:ms, number:sg];
loués v[PRED:to-rent, aux:avoir, pastp:+, gender:ms, number:pl];
louée v[PRED:to-rent, aux:avoir, pastp:+, gender:fm, number:sg];
louées v[PRED:to-rent, aux:avoir, pastp:+, gender:fm, number:pl];

louer v[PRED:to-rent, aux:aller, pastp:-, finite:-];

réserve v[PRED:to-book, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
réserves v[PRED:to-book, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
réservons v[PRED:to-book, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
réservez v[PRED:to-book, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
réservent v[PRED:to-book, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

réservais v[PRED:to-book, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
réservait v[PRED:to-book, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
réservions v[PRED:to-book, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
réserviez v[PRED:to-book, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
réservaient v[PRED:to-book, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

réserverai v[PRED:to-book, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
réserveras v[PRED:to-book, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
réservera v[PRED:to-book, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
réserverons v[PRED:to-book, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
réserverez v[PRED:to-book, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
réserveront v[PRED:to-book, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

réservé v[PRED:to-book, aux:avoir, pastp:+, gender:ms, number:sg];
réservés v[PRED:to-book, aux:avoir, pastp:+, gender:ms, number:pl];
réservée v[PRED:to-book, aux:avoir, pastp:+, gender:fm, number:sg];
réservées v[PRED:to-book, aux:avoir, pastp:+, gender:fm, number:pl];

réserver v[PRED:to-book, aux:aller, pastp:-, finite:-];

achète v[PRED:to-buy, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
achètes v[PRED:to-buy, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
achetons v[PRED:to-buy, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
achetez v[PRED:to-buy, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
achètent v[PRED:to-buy, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

achetais v[PRED:to-buy, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
achetait v[PRED:to-buy, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
achetions v[PRED:to-buy, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-buy, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
achetiez v[PRED:to-buy, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-buy, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
achetaient v[PRED:to-buy, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

acheterai v[PRED:to-buy, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
acheteras v[PRED:to-buy, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
achetera v[PRED:to-buy, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
acheterons v[PRED:to-buy, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
acheterez v[PRED:to-buy, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
acheteront v[PRED:to-buy, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

acheté v[PRED:to-buy, aux:avoir, pastp:+, gender:ms, number:sg];
achetés v[PRED:to-buy, aux:avoir, pastp:+, gender:ms, number:pl];
achetée v[PRED:to-buy, aux:avoir, pastp:+, gender:fm, number:sg];
achetées v[PRED:to-buy, aux:avoir, pastp:+, gender:fm, number:pl];

acheter v[PRED:to-buy, aux:aller, pastp:-, finite:-];

vends v[PRED:to-sold, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative];
vend v[PRED:to-sold, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:indicative];
vendons v[PRED:to-sold, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
vendez v[PRED:to-sold, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
vendent v[PRED:to-sold, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

vendais v[PRED:to-sold, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
vendait v[PRED:to-sold, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
vendions v[PRED:to-sold, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-sold, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
vendiez v[PRED:to-sold, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-sold, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
vendaient v[PRED:to-sold, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

vendes v[PRED:to-sold, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:subjunctive];
vende v[PRED:to-sold, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:subjunctive];

venderai v[PRED:to-sold, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
venderas v[PRED:to-sold, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
vendera v[PRED:to-sold, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
venderons v[PRED:to-sold, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
venderez v[PRED:to-sold, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
venderont v[PRED:to-sold, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

vendu v[PRED:to-sold, aux:avoir, pastp:+, gender:ms, number:sg];
vendus v[PRED:to-sold, aux:avoir, pastp:+, gender:ms, number:pl];
vendue v[PRED:to-sold, aux:avoir, pastp:+, gender:fm, number:sg];
vendues v[PRED:to-sold, aux:avoir, pastp:+, gender:fm, number:pl];

vendre v[PRED:to-sold, aux:aller, pastp:-, finite:-];

perds v[PRED:to-lose, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative];
perd v[PRED:to-lose, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:indicative];
perdons v[PRED:to-lose, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
perdez v[PRED:to-lose, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
perdent v[PRED:to-lose, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative|subjunctive];

perdais v[PRED:to-lose, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
perdait v[PRED:to-lose, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
perdions v[PRED:to-lose, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-lose, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:subjunctive];
perdiez v[PRED:to-lose, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative]
|v[PRED:to-lose, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:subjunctive];
perdaient v[PRED:to-lose, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

perdes v[PRED:to-lose, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:subjunctive];
perde v[PRED:to-lose, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:subjunctive];

perderai v[PRED:to-lose, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
perderas v[PRED:to-lose, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
perdera v[PRED:to-lose, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
perderons v[PRED:to-lose, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
perderez v[PRED:to-lose, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
perderont v[PRED:to-lose, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

perdu v[PRED:to-lose, aux:avoir, pastp:+, gender:ms, number:sg];
perdus v[PRED:to-lose, aux:avoir, pastp:+, gender:ms, number:pl];
perdue v[PRED:to-lose, aux:avoir, pastp:+, gender:fm, number:sg];
perdues v[PRED:to-lose, aux:avoir, pastp:+, gender:fm, number:pl];

perdre v[PRED:to-lose, aux:aller, pastp:-, finite:-];

gagne v[PRED:to-win, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
gagnes v[PRED:to-win, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
gagnons v[PRED:to-win, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
gagnez v[PRED:to-win, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
gagnent v[PRED:to-win, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

gagnais v[PRED:to-win, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
gagnait v[PRED:to-win, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
gagnions v[PRED:to-win, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
gagniez v[PRED:to-win, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
gagnaient v[PRED:to-win, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

gagnerai v[PRED:to-win, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
gagneras v[PRED:to-win, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
gagnera v[PRED:to-win, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
gagnerons v[PRED:to-win, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
gagnerez v[PRED:to-win, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
gagneront v[PRED:to-win, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

gagné v[PRED:to-win, aux:avoir, pastp:+, gender:ms, number:sg];
gagnés v[PRED:to-win, aux:avoir, pastp:+, gender:ms, number:pl];
gagnée v[PRED:to-win, aux:avoir, pastp:+, gender:fm, number:sg];
gagnées v[PRED:to-win, aux:avoir, pastp:+, gender:fm, number:pl];

gagner v[PRED:to-win, aux:aller, pastp:-, finite:-];

veux v[PRED:to-want, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
veut v[PRED:to-want, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voulons v[PRED:to-want, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voulez v[PRED:to-want, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
veulent v[PRED:to-want, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];

voulais v[PRED:to-want, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voulait v[PRED:to-want, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voulions v[PRED:to-want, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
vouliez v[PRED:to-want, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voulaient v[PRED:to-want, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];

voudrai v[PRED:to-want, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voudras v[PRED:to-want, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voudra v[PRED:to-want, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voudrons v[PRED:to-want, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voudrez v[PRED:to-want, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voudront v[PRED:to-want, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];

voulu v[PRED:to-want, aux:avoir, pastp:+, gender:ms, number:sg, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
voulus v[PRED:to-want, aux:avoir, pastp:+, gender:ms, number:pl, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
vouluée v[PRED:to-want, aux:avoir, pastp:+, gender:fm, number:sg, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];
vouluées v[PRED:to-want, aux:avoir, pastp:+, gender:fm, number:pl, scomp:[mood:subjunctive, compForm:que], vcomp:[compForm:empty]];

vouloir v[PRED:to-want, aux:aller, finite:-];

xxxe v[PRED:to-yyy, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
xxxes v[PRED:to-yyy, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
xxxons v[PRED:to-yyy, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
xxxez v[PRED:to-yyy, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
xxxent v[PRED:to-yyy, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

xxxais v[PRED:to-yyy, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
xxxait v[PRED:to-yyy, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
xxxions v[PRED:to-yyy, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
xxxiez v[PRED:to-yyy, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
xxxaient v[PRED:to-yyy, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

xxxerai v[PRED:to-yyy, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
xxxeras v[PRED:to-yyy, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
xxxera v[PRED:to-yyy, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
xxxerons v[PRED:to-yyy, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
xxxerez v[PRED:to-yyy, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
xxxeront v[PRED:to-yyy, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

xxxé v[PRED:to-yyy, aux:avoir, pastp:+, gender:ms, number:sg];
xxxés v[PRED:to-yyy, aux:avoir, pastp:+, gender:ms, number:pl];
xxxée v[PRED:to-yyy, aux:avoir, pastp:+, gender:fm, number:sg];
xxxées v[PRED:to-yyy, aux:avoir, pastp:+, gender:fm, number:pl];

xxxer v[PRED:to-yyy, aux:aller, pastp:-, finite:-];

arrive v[PRED:to-arrive, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
arrives v[PRED:to-arrive, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
arrivons v[PRED:to-arrive, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
arrivez v[PRED:to-arrive, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
arrivent v[PRED:to-arrive, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

arrivais v[PRED:to-arrive, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
arrivait v[PRED:to-arrive, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
arrivions v[PRED:to-arrive, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
arriviez v[PRED:to-arrive, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
arrivaient v[PRED:to-arrive, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

arriverai v[PRED:to-arrive, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
arriveras v[PRED:to-arrive, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
arrivera v[PRED:to-arrive, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
arriverons v[PRED:to-arrive, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
arriverez v[PRED:to-arrive, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
arriveront v[PRED:to-arrive, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

arrivé v[PRED:to-arrive, aux:avoir, pastp:+, gender:ms, number:sg];
arrivés v[PRED:to-arrive, aux:avoir, pastp:+, gender:ms, number:pl];
arrivée v[PRED:to-arrive, aux:avoir, pastp:+, gender:fm, number:sg];
arrivées v[PRED:to-arrive, aux:avoir, pastp:+, gender:fm, number:pl];

arriver v[PRED:to-arrive, aux:aller, pastp:-, finite:-];

pars v[PRED:to-depart, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative];
part v[PRED:to-depart, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:indicative];
partons v[PRED:to-depart, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
partez v[PRED:to-depart, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
partent v[PRED:to-depart, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

partais v[PRED:to-depart, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
partait v[PRED:to-depart, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
partions v[PRED:to-depart, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
partiez v[PRED:to-depart, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
partaient v[PRED:to-depart, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

partirai v[PRED:to-depart, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
partiras v[PRED:to-depart, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
partira v[PRED:to-depart, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
partirons v[PRED:to-depart, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
partirez v[PRED:to-depart, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
partiront v[PRED:to-depart, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

parti v[PRED:to-depart, aux:avoir, pastp:+, gender:ms, number:sg];
partis v[PRED:to-depart, aux:avoir, pastp:+, gender:ms, number:pl];
partie v[PRED:to-depart, aux:avoir, pastp:+, gender:fm, number:sg];
parties v[PRED:to-depart, aux:avoir, pastp:+, gender:fm, number:pl];

partir v[PRED:to-depart, aux:aller, pastp:-, finite:-];

débarque v[PRED:to-disembark, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
débarques v[PRED:to-disembark, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
débarquons v[PRED:to-disembark, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
débarquez v[PRED:to-disembark, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
débarquent v[PRED:to-disembark, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

débarquais v[PRED:to-disembark, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
débarquait v[PRED:to-disembark, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
débarquions v[PRED:to-disembark, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
débarquiez v[PRED:to-disembark, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
débarquaient v[PRED:to-disembark, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

débarquerai v[PRED:to-disembark, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
débarqueras v[PRED:to-disembark, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
débarquera v[PRED:to-disembark, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
débarquerons v[PRED:to-disembark, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
débarquerez v[PRED:to-disembark, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
débarqueront v[PRED:to-disembark, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

débarqué v[PRED:to-disembark, aux:avoir, pastp:+, gender:ms, number:sg];
débarqués v[PRED:to-disembark, aux:avoir, pastp:+, gender:ms, number:pl];
débarquée v[PRED:to-disembark, aux:avoir, pastp:+, gender:fm, number:sg];
débarquées v[PRED:to-disembark, aux:avoir, pastp:+, gender:fm, number:pl];

débarquer v[PRED:to-disembark, aux:aller, pastp:-, finite:-];

conduis v[PRED:to-drive, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative];
conduit v[PRED:to-drive, pastp:-, subj:[person:3, number:sg], tense:present, finite:+, mood:indicative];
conduisons v[PRED:to-drive, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
conduisez v[PRED:to-drive, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
conduisent v[PRED:to-drive, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

conduirais v[PRED:to-drive, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
conduirait v[PRED:to-drive, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
conduirions v[PRED:to-drive, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
conduiriez v[PRED:to-drive, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
conduiraient v[PRED:to-drive, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

conduirerai v[PRED:to-drive, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
conduireras v[PRED:to-drive, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
conduirera v[PRED:to-drive, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
conduirerons v[PRED:to-drive, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
conduirerez v[PRED:to-drive, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
conduireront v[PRED:to-drive, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

conduiré v[PRED:to-drive, aux:avoir, pastp:+, gender:ms, number:sg];
conduirés v[PRED:to-drive, aux:avoir, pastp:+, gender:ms, number:pl];
conduirée v[PRED:to-drive, aux:avoir, pastp:+, gender:fm, number:sg];
conduirées v[PRED:to-drive, aux:avoir, pastp:+, gender:fm, number:pl];

conduirer v[PRED:to-drive, aux:aller, pastp:-, finite:-];

décolle v[PRED:to-take-of, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
décolles v[PRED:to-take-of, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
décollons v[PRED:to-take-of, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
décollez v[PRED:to-take-of, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
décollent v[PRED:to-take-of, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

décollais v[PRED:to-take-of, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
décollait v[PRED:to-take-of, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
décollions v[PRED:to-take-of, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
décolliez v[PRED:to-take-of, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
décollaient v[PRED:to-take-of, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

décollerai v[PRED:to-take-of, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
décolleras v[PRED:to-take-of, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
décollera v[PRED:to-take-of, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
décollerons v[PRED:to-take-of, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
décollerez v[PRED:to-take-of, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
décolleront v[PRED:to-take-of, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

décollé v[PRED:to-take-of, aux:avoir, pastp:+, gender:ms, number:sg];
décollés v[PRED:to-take-of, aux:avoir, pastp:+, gender:ms, number:pl];
décollée v[PRED:to-take-of, aux:avoir, pastp:+, gender:fm, number:sg];
décollées v[PRED:to-take-of, aux:avoir, pastp:+, gender:fm, number:pl];

décoller v[PRED:to-take-of, aux:aller, pastp:-, finite:-];

atterris v[PRED:to-land, pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative];
atterrit v[PRED:to-land, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative];
atterrissons v[PRED:to-land, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
atterrissez v[PRED:to-land, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
atterrissent v[PRED:to-land, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

atterrissais v[PRED:to-land, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
atterrissait v[PRED:to-land, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
atterrissions v[PRED:to-land, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
atterrissiez v[PRED:to-land, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
atterrissaient v[PRED:to-land, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

atterrirai v[PRED:to-land, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
atterriras v[PRED:to-land, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
atterrira v[PRED:to-land, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
atterrirons v[PRED:to-land, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
atterrirez v[PRED:to-land, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
atterriront v[PRED:to-land, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

atterri v[PRED:to-land, aux:avoir, pastp:+, gender:ms, number:sg];
atterris v[PRED:to-land, aux:avoir, pastp:+, gender:ms, number:pl];
atterrie v[PRED:to-land, aux:avoir, pastp:+, gender:fm, number:sg];
atterries v[PRED:to-land, aux:avoir, pastp:+, gender:fm, number:pl];

atterrir v[PRED:to-land, aux:aller, pastp:-, finite:-];

navigue v[PRED:to-sail, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
navigues v[PRED:to-sail, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
naviguons v[PRED:to-sail, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
naviguez v[PRED:to-sail, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
naviguent v[PRED:to-sail, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

naviguais v[PRED:to-sail, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
naviguait v[PRED:to-sail, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
naviguions v[PRED:to-sail, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
naviguiez v[PRED:to-sail, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
naviguaient v[PRED:to-sail, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

naviguerai v[PRED:to-sail, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
navigueras v[PRED:to-sail, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
naviguera v[PRED:to-sail, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
naviguerons v[PRED:to-sail, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
naviguerez v[PRED:to-sail, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
navigueront v[PRED:to-sail, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

navigué v[PRED:to-sail, aux:avoir, pastp:+, gender:ms, number:sg];
navigués v[PRED:to-sail, aux:avoir, pastp:+, gender:ms, number:pl];
naviguée v[PRED:to-sail, aux:avoir, pastp:+, gender:fm, number:sg];
naviguées v[PRED:to-sail, aux:avoir, pastp:+, gender:fm, number:pl];

naviguer v[PRED:to-sail, aux:aller, pastp:-, finite:-];

remorque v[PRED:to-tow, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
remorques v[PRED:to-tow, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
remorquons v[PRED:to-tow, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
remorquez v[PRED:to-tow, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
remorquent v[PRED:to-tow, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

remorquais v[PRED:to-tow, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
remorquait v[PRED:to-tow, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
remorquions v[PRED:to-tow, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
remorquiez v[PRED:to-tow, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
remorquaient v[PRED:to-tow, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

remorquerai v[PRED:to-tow, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
remorqueras v[PRED:to-tow, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
remorquera v[PRED:to-tow, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
remorquerons v[PRED:to-tow, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
remorquerez v[PRED:to-tow, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
remorqueront v[PRED:to-tow, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

remorqué v[PRED:to-tow, aux:avoir, pastp:+, gender:ms, number:sg];
remorqués v[PRED:to-tow, aux:avoir, pastp:+, gender:ms, number:pl];
remorquée v[PRED:to-tow, aux:avoir, pastp:+, gender:fm, number:sg];
remorquées v[PRED:to-tow, aux:avoir, pastp:+, gender:fm, number:pl];

remorquer v[PRED:to-tow, aux:aller, pastp:-, finite:-];

vole v[PRED:to-fly, pastp:-, subj:[person:1|3, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
voles v[PRED:to-fly, pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative|subjunctive];
volons v[PRED:to-fly, pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative];
volez v[PRED:to-fly, pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative];
volent v[PRED:to-fly, pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative];

volais v[PRED:to-fly, pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
volait v[PRED:to-fly, pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
volions v[PRED:to-fly, pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
voliez v[PRED:to-fly, pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];
volaient v[PRED:to-fly, pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative];

volerai v[PRED:to-fly, pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
voleras v[PRED:to-fly, pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
volera v[PRED:to-fly, pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
volerons v[PRED:to-fly, pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
volerez v[PRED:to-fly, pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];
voleront v[PRED:to-fly, pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative];

volé v[PRED:to-fly, aux:avoir, pastp:+, gender:ms, number:sg];
volés v[PRED:to-fly, aux:avoir, pastp:+, gender:ms, number:pl];
volée v[PRED:to-fly, aux:avoir, pastp:+, gender:fm, number:sg];
volées v[PRED:to-fly, aux:avoir, pastp:+, gender:fm, number:pl];

voler v[PRED:to-fly, aux:aller, pastp:-, finite:-];

//faire de la moto/du cheval/du vélo
//prendre une moto/un cheval/un vélo

fais v[PRED:to-ride(X), pastp:-, subj:[person:1|2, number:sg], tense:present, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
fait v[PRED:to-ride(X), pastp:-, subj:[person:2, number:sg], tense:present, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
faisons v[PRED:to-ride(X), pastp:-, subj:[person:1, number:pl], tense:present, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
faites v[PRED:to-ride(X), pastp:-, subj:[person:2, number:pl], tense:present, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
font v[PRED:to-ride(X), pastp:-, subj:[person:3, number:pl], tense:present, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];

faisais v[PRED:to-ride(X), pastp:-, subj:[person:1|2, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
faisait v[PRED:to-ride(X), pastp:-, subj:[person:3, number:sg], tense:past, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
faisions v[PRED:to-ride(X), pastp:-, subj:[person:1, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
faisiez v[PRED:to-ride(X), pastp:-, subj:[person:2, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
faisaient v[PRED:to-ride(X), pastp:-, subj:[person:3, number:pl], tense:past, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];

ferai v[PRED:to-ride(X), pastp:-, subj:[person:1, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
feras v[PRED:to-ride(X), pastp:-, subj:[person:2, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
fera v[PRED:to-ride(X), pastp:-, subj:[person:3, number:sg], tense:future, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
ferons v[PRED:to-ride(X), pastp:-, subj:[person:1, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
ferez v[PRED:to-ride(X), pastp:-, subj:[person:2, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];
feront v[PRED:to-ride(X), pastp:-, subj:[person:3, number:pl], tense:future, aspect:unaccomplished, finite:+, mood:indicative, objC:[PRED:X, det:+, part:+, number:sg]];

fait v[PRED:to-ride(X), aux:avoir, pastp:+, gender:ms, number:sg, objC:[PRED:X, det:+, part:+, number:sg]];
faits v[PRED:to-ride(X), aux:avoir, pastp:+, gender:ms, number:pl, objC:[PRED:X, det:+, part:+, number:sg]];
faite v[PRED:to-ride(X), aux:avoir, pastp:+, gender:fm, number:sg, objC:[PRED:X, det:+, part:+, number:sg]];
faites v[PRED:to-ride(X), aux:avoir, pastp:+, gender:fm, number:pl, objC:[PRED:X, det:+, part:+, number:sg]];

faire v[PRED:to-ride(X), aux:aller, pastp:-, finite:-, objC:[PRED:X, det:+, part:+, number:sg]];

ne	clneg[];
pas	advneg[];

si	csu[compForm:si];
//que -> prel

de prep[pcas:de]|de[];
à prep[pcas:à]|à[];
par prep[pcas:par];
pour prep[pcas:pour];
sur prep[pcas:sur];
avant prep[pcas:avant];
après prep[pcas:après];
contre prep[pcas:contre];

que	prel [fct:obj]
	|csu[compForm:que];
qui	prel [fct:subj];

bleu	adj[PRED:blue, post:yes, gender:ms, number:sg];
bleue	adj[PRED:blue, post:yes, gender:fm, number:sg];
bleus	adj[PRED:blue, post:yes, gender:ms, number:pl];
bleues	adj[PRED:blue, post:yes, gender:fm, number:pl];

jaune	adj[PRED:yellow, post:yes, number:sg];
jaunes	adj[PRED:yellow, post:yes, number:pl];

rouge	adj[PRED:red, post:yes, number:sg];
rouges	adj[PRED:red, post:yes, number:pl];

blanc	adj[PRED:white, post:yes, gender:ms, number:sg];
blanche	adj[PRED:white, post:yes, gender:fm, number:sg];
blancs	adj[PRED:white, post:yes, gender:ms, number:pl];
blanches	adj[PRED:white, post:yes, gender:fm, number:pl];

vert	adj[PRED:green, post:yes, gender:ms, number:sg];
verte	adj[PRED:green, post:yes, gender:fm, number:sg];
verts	adj[PRED:green, post:yes, gender:ms, number:pl];
vertes	adj[PRED:green, post:yes, gender:fm, number:pl];

orange	adj[PRED:orange, post:yes, number:sg];
oranges	adj[PRED:orange, post:yes, number:pl];

violet	adj[PRED:violet, post:yes, gender:ms, number:sg];
violette	adj[PRED:violet, post:yes, gender:fm, number:sg];
violets	adj[PRED:violet, post:yes, gender:ms, number:pl];
violettes	adj[PRED:violet, post:yes, gender:fm, number:pl];

noir	adj[PRED:black, post:yes, gender:ms, number:sg];
noire	adj[PRED:black, post:yes, gender:fm, number:sg];
noirs	adj[PRED:black, post:yes, gender:ms, number:pl];
noires	adj[PRED:black, post:yes, gender:fm, number:pl];

petit	adj[PRED:small, pre:yes, gender:ms, number:sg];
petite	adj[PRED:small, pre:yes, gender:fm, number:sg];
petits	adj[PRED:small, pre:yes, gender:ms, number:pl];
petites	adj[PRED:small, pre:yes, gender:fm, number:pl];

grand	adj[PRED:tall, pre:yes, gender:ms, number:sg];
grande	adj[PRED:tall, pre:yes, gender:fm, number:sg];
grands	adj[PRED:tall, pre:yes, gender:ms, number:pl];
grandes	adj[PRED:tall, pre:yes, gender:fm, number:pl];

gros	adj[PRED:big, pre:yes, gender:ms];
grosse	adj[PRED:big, pre:yes, gender:fm, number:sg];
grosses	adj[PRED:big, pre:yes, gender:fm, number:pl];

maigre	adj[PRED:thin, post:yes, number:sg, anim:yes];
maigres	adj[PRED:thin, post:yes, number:pl, anim:yes];

//étroit	adj[PRED:thin, post:yes, gender:ms, number:sg, anim:no];
//étroits	adj[PRED:thin, post:yes, gender:ms, number:pl, anim:no];
//étroite	adj[PRED:thin, post:yes, gender:fm, number:sg, anim:no];
//étroites	adj[PRED:thin, post:yes, gender:fm, number:pl, anim:no];

léger	adj[PRED:thin, post:yes, gender:ms, number:sg, anim:no];
légers	adj[PRED:thin, post:yes, gender:ms, number:pl, anim:no];
légère	adj[PRED:thin, post:yes, gender:fm, number:sg, anim:no];
légères	adj[PRED:thin, post:yes, gender:fm, number:pl, anim:no];

';
?>
