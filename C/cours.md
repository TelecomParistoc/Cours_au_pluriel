<!---Message à l'intention d'Arnaud : tout commit est interdit sur ce fichier sinon git reset dans les dents! !-->

#Sommaire

1. Etapes de compilation
2. Types de base
3. Instructions, opérateurs et blocs conditionnels
4. Fonctions
5. Préprocesseur
6. Bibliothèque standard
7. Entrées sorties
8. Structures
9. Tableaux
10. Allocation dynamique

Cours de référence à l'adresse https://www.rocq.inria.fr/secret/Anne.Canteaut/COURS_C/


###1. Etapes de compilation

####But : passer d'un code source à un binaire exécutable sur la machine

- Preprocessing : transformations textuelles (inclusion de fichiers sources, remplacements de chaînes)
  Directives préfixées par un #

Exemple :
  <code>
  #ifdef \__unix\__
  # include <unistd.h>
  #elif defined _WIN32
  # include <windows.h>
  #endif</code>

- Compilation :
