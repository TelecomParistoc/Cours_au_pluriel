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

    #ifdef __unix__<br/>
    # include <unistd.h><br/>
    #elif defined _WIN32<br/>
    # include <windows.h><br/>
    #endif</code><br/>

- Compilation : conversion du code C en code assembleur

    gcc -S src.c -o src.s

    (très rarement (jamais) utilisé)

- Assemblage : traduction du code assembleur vers des instructions machines compréhensibles par le processeur

    gcc -c src.c -o src.o

- Edition de liens : assemblage des différents fichiers objets/librairies utilisées pour le projet (résolution des liens)

    gcc src1.o src2.o -o built

    ou bien gcc src.c -o built

    (built est alors un exécutable fonctionnel ou une librairie pré-compilée (dans ce cas lui donner l'extension .a))


###2. Types de base

Variable = mémoire = N bits où N dépend du type de la Variable

Types peu abstraits (pas de string en C, pas de notion d'objets) et non universels (sauf exception, même si dans la majorité des cas on retrouve le même nombre d'octets pour un type donné)

|-|-|-|-|-|-|-|-|   (1 case = 1 octet)

|-|                 char (universel), uint8_t

|-|-|               short int, uint16_t

|-|-|-|-|           int, float, uint32_t

|-|-|-|-|-|-|-|-|   double, uint64_t

Pour avoir confirmation de la taille effective sur la machine, on peut effectuer un sizeof(type). Par exemple : printf("%d",sizeof(char)); affichera "1" dans tous les cas.

####Qualitifs de type

1 octet = 8 bits

100 = 0b01100100 = 0x64

-100 = 0b10011100 = 0x9c

Par défaut les types sont signés :

char a <=> signed char a
MAIS
char a >< unsigned char a

*Exemple :*

char a = 156;  //(10011100)
printf("%d",a); //affiche -100
unsigned char b = 156;  //(10011100)
printf("%d",b); //affiche 158
