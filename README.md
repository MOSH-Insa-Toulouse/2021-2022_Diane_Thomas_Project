# 2021-2022_Diane_Thomas_Project
Protocol de réalisation de capteurs low-tech à base de graphite



## Sommaire
- [2021-2022_Diane_Thomas_Project](#2021-2022_diane_thomas_project)
 
  - [Test circuit avec LT-Spice](#test-circuit-avec-lt-spice)
  - [Réalisation PCB KICAD](#réalisation-pcb-kicad)
  - [Réalisation PCB physique](#réalisation-pcb-physique)
  - [Code Arduino](#code-arduino)
  - [APK MIT AppInventor](#apk-mit-appinventor)
  - [Banc de test](#banc-de-test)
  - [Amélioration à apporter](#amélioration-à-apporter)
  - [Point d'amélioration](#point-damélioration)
  - [Auteurs](#auteurs)







### Test circuit avec LT-Spice

![Circuit_suggéré](https://user-images.githubusercontent.com/98905793/161027466-d61d4278-4927-4314-a9a8-1a1a7b82081c.png)


Nous avons commencé par réaliser le circuit trans-impédance ci-dessus sur LT-Spice afin de déterminer la fonction de chaque filtre sur le circuit et aussi déterminer l'atténuation globale d'un bruit en courant de 50 Hz et aussi l'atténuation globale d'un bruit en courant à la fréquence limite de repliement.

1.1. Etude des filtres

Pour chaque filtre nous avons mesuré la fréquence de coupure expérimentalement avec LT-Spise et ensuite nous avons fait le calcul théorique avec la formule *fc=1/2*pi*R*C. Nous avons obtenus des valeurs expérimentales et théoriques très proches pour chaque filtre.

- Visualisation mesure filtre *R1C1*
![filtre 1 R1C1](https://user-images.githubusercontent.com/98905793/161029367-5dfc7286-252c-4cfc-b5d7-4620bdf10430.PNG)

Fréquence de coupure mesurée d'environ *16Hz*, ce filtre sert à filtrer le bruit de courant et aussi d'éviter les bruits de hautes fréquences causé par distorsion dans les étages d'entrée 

- Visualisation mesures filtre *R3C4*
![filtre 2 R3C4](https://user-images.githubusercontent.com/98905793/161031602-96b18b47-e291-45e6-9dd0-08b9a9dc2465.PNG)

Fréquence de coupure d'environ 1.6Hz, c'est un filtre actif passe bas qui permet d'avoir le maximum d'efficacité en maintenant le  gain de ?? constant.

- Visualition filtre R6C2
![filtre 3 R6C2](https://user-images.githubusercontent.com/98905793/161031729-e01387f3-db88-49cd-977a-db9e50c20280.PNG)

 Fréquence de coupure d'environ 1.6kHz, c'est le filtre de sortie qui permet d'adapter la fréquence du signal à la carte ADC arduino. Il empêche les les fréquences élevées (bruit d'alimentation...) de passé dans l'ADC
 
 - La capacité C3 elle permet de filtrer le bruit d'alimentation.
 
 1.2. Etude de l'atténuation à la fréquence de coupure et à la fréquence de niquyst
 Gain global obtenu ~140dB
 - Atténuation à la fréquence de 50Hz
 ![gain 50Hz](https://user-images.githubusercontent.com/98905793/161033772-1902ba1a-6215-4486-ac87-026ffd8e7faa.PNG)
 A 50Hz on mesure un gain ~100dB ce qui traduit une atténution de ~ 40dB
 
 - Atténuation à la fréquence de niquyst=7.5kH
 ![gain fnyquist](https://user-images.githubusercontent.com/98905793/161033708-c0863d95-892a-4406-a164-a4cd5fa764ea.PNG)
 A fniquyst on a un gain de 32.8dB, ce qui traduit une atténuation de ~ 100dB
 
 
 

## Réalisation PCB KICAD

Pour la réalisation de notre PCB nous avons utilisé le logiciel KICAD. Nous avons d'abord effectué le schématique en assignant à chaque composants (Bluetooth, oled, encodeur rotatoire) une empreinte et un symbole que nous avons réalisé, ensuite nous avons assigné à chaque composant un motif 3D dans pour la visualisation fait le routage de notre PCB, et enfin nous avons effectué le routage de notre carte

2.1. Schématique

![Schématique](https://user-images.githubusercontent.com/98905793/161578505-547fc367-0eae-473f-96f7-5a51b1d9bc94.png)

2.2. Symbole et Empreinte des composants

-Module bluetooth

![Module_bluetooth](https://user-images.githubusercontent.com/98905793/161592737-143bc7c7-3068-4333-93f5-85c8d5d00196.png)


-Encodeur rotatoire

![encodeur_rotatoire](https://user-images.githubusercontent.com/98905793/161592620-12e2ea18-629f-47c3-a090-60c556da0042.png)


-Oled

![Oled](https://user-images.githubusercontent.com/98905793/161592788-2df53909-a14c-45ce-bc2a-833ea473ee02.png)


2.3 Carte PCB 

![Carte_PCB](https://user-images.githubusercontent.com/98905793/161579979-e78d3553-924d-4140-9f97-e6bd357a53aa.png)


2.4 Carte PCB visu 3d

![Visu3d](https://user-images.githubusercontent.com/98905793/161579875-fbbe4a1d-7de7-44ed-8657-5575cc9e2078.png)




## Réalisation PCB physique
Nous avons imprimé notre circuit sur une carte d'époxy recouverte de cuivre qui est lui même couvert par une résine positive photosensible.
Notre circuit a d'abord été imprimé(avec une imprimante classique à l'encre) sur du papier plastique transparent. 
Les motifs ont été ensuite transferrés sur la carte par insolation aux UV et un passage au développeur pour dissoudre la résine insolée.
Ensuite nous passons la carte dans un bain de perclorure de fer pour dissoudre les parties métalliques qui ont été revélées lors de l'insolation. 
Après cette étape, nous rinçons notre carte à l'eau et la plongeons dans un bain d'acétone pour enlever la résine qui protégeait les autres parties du circuit. 
Enfin l'on rince encore à l'eau et voilà, notre carte est prête. 
On utilise un forêt pour le perçage et enfin on soude les composants(résistances, capacités, amplificateur,..... ) sur la carte.

![CartePCB_marche](https://user-images.githubusercontent.com/98905793/163810848-d19a8177-2954-4b40-8d5b-c6eb3ca76b1a.jpg)


## Code Arduino 
Dans notre code arduino, nous récuperons la valeur de la tension de notre capteur que nous convertissons en résistance. Nous affichons cette tension et cette  résistance sur l'oled et sur l'application que nous avons réalisée sur MIT AppIventor

Vous trouverez le code ici  .

## APK MIT AppInventor
Pour Installer l'application, il vous suffit de télecharger le fichier .apk sur votre télephone et de l'installer.
Vous trouverez ce fichier dans ce dosssier ![APK app inventor](https://github.com/MOSH-Insa-Toulouse/2021-2022_Diane_Thomas_Project/tree/main/APK%20app%20inventor).
L'application permet de lire les valeurs de résistance et de tension mesurées, et aussi de voir la courbe de mesure de la résistance.
Un bouton vous permet de vous connecter et vous déconnecter. Après la mesure il est possible de récuperer les valeurs de tension et de résistance mesurées dans un fichier txt qui s'enregistre automatiquement dans vos documents.

![APK](https://user-images.githubusercontent.com/98905793/163808292-009867f8-d38c-4246-9833-f37e429a7070.png)


## Banc de test

Nous avons effectué notre banc de test en utilisant des cylindres de différents diamètres(1, 1.5, 2, 2.5, 3, 3.5, 4 cm) fabriqués avec du du papier recyclé. On met le capteur en tension, en le faisant épouser la forme des différents cylindre).
Les resultats peuvent être consulté ici .
![Cylindre_banc_test](https://user-images.githubusercontent.com/98905793/163810617-1eadc30e-e6a0-4842-b525-158685afb5b0.jpg)


## Amélioration à apporter
Notre banc de test présente certaines limites et peut être amélioré.
On a:

- La non répétabilité des mesures. En effet, les déformations appliquées peuvent varier entre chaque mesure: le banc de test ne permet pas d’appliquer une déformation identique. On pourrait envisager un banc de test fonctionnant avec un servomoteur par exemple (Ce système permet de générer des contraintes avec des angles bien présice et d'obtenir, de ce fait, une meilleure reproductibilité)

- Le dépôt de graphite sur le papier qui ne peut pas être maitriser cela conduit une variation de mesure pour différents dépôt de même graphite.

-la déformation irréversible du capteur après un certains nombres de mesures.

#### Point d'amélioration

Afin de pouvoir lire une plus grande plage de résistance tout en ayant des mesures stables, il faudrait pouvoir changer le gain du circuit transimpédance c'est à dire modifier la résistance R2 (voir schéma KiCad ). Cependant nous l'avons soudée sur le circuit PCB. Il faut donc à la place de la résistance R2 mettre un potentiomètre qui permet de varier  celle-ci.


## Auteurs
  
  - Bonkoungou Diane bonkoung@etud.insa-toulouse.fr
  - Bousquet Thomas tbousque@etud.insa-toulouse.fr


