# 2021-2022_Diane_Thomas_Project
Protocol de réalisation de capteurs low-tech à base de graphite

Réalisation du PCB avec KICAD: Nous avons créer les symboles et les empreintes des composants qui n'existent pas(Amplificateur LT1050,Encodeur rotatoire, Module bluetooth, capteur)







## Première partie: Test du circuit électrique avec LT-Spice
![Circuit_suggéré](https://user-images.githubusercontent.com/98905793/161027466-d61d4278-4927-4314-a9a8-1a1a7b82081c.png)


Nous avons commencé par réaliser le circuit trans-impédance ci-dessus sur LT-Spice afin de déterminer la fonction de chaque filtre sur le circuit et aussi déterminer l'atténuation globale d'un bruit en courant de 50 Hz et aussi l'atténuation globale d'un bruit en courant à la fréquence limite de repliement.
Pour chaque filtre nous avons mesuré la fréquence de coupure expérimentalement avec LT-Spise et ensuite nous avons fait le calcul théorique avec la formule *fc=1/2*pi*R*C. Nous avons obtenus des valeurs expérimentales et théoriques très proches pour chaque filtre.








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

