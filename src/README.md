## A faire
- [ ] Tests parser en profondeur
- [ ] Si tests ok, mettre au propre + finir doc (preciser entrees/sorties)
- [ ] Affichage process visu
- [ ] Visu verifier affiche process bonne position // finir les instructions
- [ ] Visu verifier affiche process bonne couleur // finir les instructions
- [ ] La VM :/
- [ ] Instructions avec adressage restreint a refaire
- [ ] Valider les instructions que j'ai faites ou les corriger.
- [ ] Pas de leaks, mais pas du tout a la norme.

## Fait
- [x] Option v lors du parsing, et verif des bits sets avec masks.
- [x] Nombre variable de champions (voir op.h)
- [x] verifier numero process valides => permetra de generaliser l'initialisation des process.
- [x] Generer une liste chainee avec les champions
- [x] Recuperer le nom, la description, le poids et le code de chaque champion
- [x] Initialisation des process dans boucle.
- [x] Chargement des programmes en memoire
- [x] Probleme parser./corewar tests/champs/Gagnant.cor tests/champs/examples/zork.cor -n 13 tests/champs/Gagnant.cor tests/champs/Car.cor -v 2 -n
- [x] l'option v ne march plus.
- [x] Il n'y avait pas de exit dans le ft\_error\_parse. C'est moi qui l'qi oublie, ou quelqu'un l'avait enleve pour une bonne raison ?
- [x] Aller bouffer
