# 2021-2022_Diane_Thomas_Project
Protocol de réalisation de capteurs low-tech à base de graphite

Réalisation du PCB avec KICAD: Nous avons créer les symboles et les empreintes des composants qui n'existent pas(Amplificateur LT1050,Encodeur rotatoire, Module bluetooth, capteur)







## Première partie: Test du circuit électrique avec LT-Spice
![Circuit_suggéré](https://user-images.githubusercontent.com/98905793/161027466-d61d4278-4927-4314-a9a8-1a1a7b82081c.png)


Nous avons commencé par réaliser le circuit trans-impédance ci-dessus sur LT-Spice afin de déterminer la fonction de chaque filtre sur le circuit et aussi déterminer l'atténuation globale d'un bruit en courant de 50 Hz et aussi l'atténuation globale d'un bruit en courant à la fréquence limite de repliement.

1. Etude des filtres

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
 
 2. Etude de l'atténuation à la fréquence de coupure et à la fréquence de niquyst
 Gain global obtenu ~140dB
 - Atténuation à la fréquence de 50Hz
 ![gain 50Hz](https://user-images.githubusercontent.com/98905793/161033772-1902ba1a-6215-4486-ac87-026ffd8e7faa.PNG)
 A 50Hz on mesure un gain ~100dB ce qui traduit une atténution de ~ 40dB
 
 - Atténuation à la fréquence de niquyst=7.5kH
 ![gain fnyquist](https://user-images.githubusercontent.com/98905793/161033708-c0863d95-892a-4406-a164-a4cd5fa764ea.PNG)
 A fniquyst on a un gain de 32.8dB, ce qui traduit une atténuation de ~ 100dB
 
 
 








## Installation
TODO: Describe the installation process
## Usage
TODO: Write usage instructions
## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D
## History
TODO: Write history
## Credits
TODO: Write credits
## License
TODO: Write license
## Roadmap
  - [ ] things
  - [ ] things
  - [ ] things

