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
9. Tableaux/Pointeurs
10. Allocation dynamique

Cours de référence à l'adresse https://www.rocq.inria.fr/secret/Anne.Canteaut/COURS_C/


###1. Etapes de compilation

####But : passer d'un code source à un binaire exécutable sur la machine

- Preprocessing : transformations textuelles (inclusion de fichiers sources, remplacements de chaînes). Directives préfixées par un #

Exemple :

    #ifdef __unix__
    # include <unistd.h>
    #elif defined _WIN32
    # include <windows.h>
    #endif

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

Attention : les caractères ne sont pas des types spéciaux, ils correspondent juste à une valeur (ascii, cf table correspondante). Exemple : char c = 'A'; // c vaut 0x41 = 65

Pour former des chaînes de caractères, cela correspond à des tableaux de chars : char* x = "bonjour"; char x[] = "bonjour"; char x[10] = "bonjour". ' et " n'ont donc pas du tout la même signification.

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

**Complément à 2 **

x = 10001010

On inverse les bits

01110101

On rajoute 1

-x = 01110110

On obtient la représentation binaire de -x


###3. Instructions, opérateurs et blocs conditionnels

Commentaires : // jusqu'à la fin de la ligne où /* jusqu'au prochain */

Une instruction se termine toujours par un ";". Avant le ";", ça doit former une expression syntaxiquement valide.

Les opérateurs sont classiques :

- = ++ -- [operateur bit à bit ou élémentaire]= pour l'affectation

- + / * % - pour les opérations élémenaires

- ^ & | ~ >> << pour les opérations bits à bits

- == != < > <= >= ! && || pour les opérations booléennes

- [] * pour l'accès à une zone mémoire

- & pour l'accès à une adresse


Les blocs conditionnels également et si ce qui doit s'exécuter à l'intérieur fait plus d'une ligne il faut rajouter des accolades (sinon ça n'est pas obligatoire si il n'y a qu'une seule instruction à exécuter) :

- if(expr){}[else if{}]...[else if{}][else{}]

- while(expr){}

- do{}while(expr);

- for(i=0;i<10;i++){}

- switch(expr){case 1: ...; break; case 2: ...; break; ... default: break;}

- x = (expr)?a:b; (opérateur ternaire : si expr est vérifiée, x prend la valeur a, sinon b)

- break et continue dans une boucle pour soit en sortir (break), soit passer au tour de boucle suivant sans exécuter les opérations entre (continue)


###4. Fonctions

Comme en java :

type nom(argument(s))
{}

Exemples :

char get_char_of(int a)
{return a&255;}

void print_bonjour()
{printf("bonjour\n");}


###5. Préprocesseur

- Inclusion des fichiers contenant les prototypes (juste la ligne "type nom(argument(s))") des fonctions utilisées dans le fichier qui contient l'include.

\#include<nom_bibliotheque.h>

\#include<nom_fichier.h>

- Définition de constantes, de MACRO

\#define PI 3.14159265
\#define a(x) x*x

- Vérification d'inclusion déjà réalisée (pour éviter les inclusions mutliples)

\#ifdef TRUC_QUI_DIT_QUE_LES_PROTOTYPES_DES_FONCTIONS_SONT_DEJA_IMPORTEES

(suivi éventuellement d'un #elif, d'un #else, puis finalement d'un #endif)


###6. Bibliothèque standard

Contient de nombreuses fonctions de bases utiles dans beaucoup de contextes.

-Affichage/écriture : printf, puts, putchar, fprintf, write ...

-Lecture : scanf, gets, fgets, read, ...

-Opérations sur les chaînes de caractères : strcat, strcmp, strchr, ...

-Opérations mathématiques standard : cos, atan, sqrt, ...

-Et un tas d'autres : exit, pause, sleep, getpid, ...

Dans stdio.h, stdlib.h, unistd.h, string.h, math.h, ...

(Recherchez libC pour avoir une idée des possibilités (basiques) offertes)


###7. Entrées sorties

Plusieurs possibiliés. Celle qui offre le plus de souplesse est celle qui utilise printf dans stdio.h.

En effet on dispose de nombreux formats d'impression :

-%d 	décimale signée

-%u 	décimale non signée

-%o 	octale non signée

-%x 	hexadécimale non signée

-%f 	décimale

-%c 	caractère

-%s 	chaîne de caractères

- ...

Plus de nombreux autres caractères spéciaux utilisés pour avoir le formatage désiré (cf la doc de printf)

Pour la lecture de caractères et un formatage facile et rapide on pourra utiliser scanf. Mais attention à ne pas en abuser, c'est une fonction dangereuse par nature (quand on veut capturer une chaîne de caractères). Les formats d'impression sont les mêmes.

Les autres fonctions sont principalement du caractère par caractère ou de la lecture de chaîne avec divers paramètres supplémentaires.

Certaines permettent de lire/écrire dans n'importe quoi (par exemple descripteur de fichier quand on veut lire le contenu d'un fichier).


8. Structures

struct a
{
    char b;
    int c;
};

struct a my_struct = {'o',100};
printf("%c %d\n", my_struct.b, my_struct.c);


9. Tableaux/Pointeurs

Un schéma vaut mieux qu'un long discours

10. Allocation dynamique
