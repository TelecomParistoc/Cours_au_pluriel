# AX12 et Raspberry Pi

## Connection au Raspberry Pi

Pour se connecter, il faut être sur le même réseau local, connectez-vous à notre routeur préféré, sushiwep !

Ensuite, allez voir du côté de [RPC](http://bonetti.io/rpc/), pour trouver l'IP du RaspberryPi qui vous intéresse. 

Ils ont des noms, nous allons utiliser "pi3" et "pi32" (BTW si vous avez des idées de noms plus marrants je prends).
"keypi" est le Pi qui controle la serrure. Inutile d'essayer de s'y connecter, vous n'aurez pas les autorisations ;).

Connectez-vous avec :

```bash
ssh pi@<IP du Pi>
```

Normalement, pas de mot de passe à entrer.

Vous pouvez tester la shell interactive des AX12 :
```bash
AX12
```
## PiRun
 
Pour tester un programme qu'on a sur son ordi perso sur le Raspberry Pi, il faut :
* récupérer l'IP du Raspberry Pi (qui change)
* copier les fichiers vers le Pi avec scp (long et chiant) ou git (un peu sale)
* se loguer sur le Pi
* compiler et executer (souvent à base de make)
 
[PiRun automatise tout ça.](https://github.com/superpingu/PiRun)
  
Pour lancer votre programme, utilisez `pirun <nom du pi> . <nom du target make>` à la racine de projet.

**Note :** Ca risque d'être assez long la première fois. Pour éviter ça, créer le fichier `.pirunignore` et ajouter `.git` et `.pirun.*` (un par ligne).

Par exemple, si vous avez un Makefile du genre :

```Makefile
all: compile run

compile: programme.c
    ...
run:
    ./programme
```

Lancer `pirun pi3 . all` compilera et executera le programme sur le Raspberri Pi "pi3".

## Qu'est-ce qu'un AX12 ?
 
[Datasheet](http://www.trossenrobotics.com/images/productdownloads/AX-12(English).pdf)
 
## Utilisation de la bibliothèque

Pour contrôler les AX12, on a écrit une [bibliothèque](https://github.com/TelecomParistoc/WalkingDriver).

Il faut ajouter le flag `-lwalkingdriver` au moment du link.

Ensuite, incluez l'ensemble des headers dans votre code :

```c
#include "walkingdriver/driver.h"
```

Et initialisez le contrôleur d'AX12 *(obligatoire)* en ajoutant au début du main :

```c
initAX12(115200);
```

l'argument 115200 est le *baudrate* de la liasion série, c'est à dire la vitesse de communication avec les AX12. Tous nos AX12 sont réglés pour communiquer à cette vitesse.

Les fonctions disponibles sont déclarée et documentée dans [ax12driver.h](https://github.com/TelecomParistoc/WalkingDriver/blob/master/src/ax12driver.h).

### Hello AX12 ! ###
Faites bouger l'AX12 jusqu'à +90° à 50% de vitesse et 50% de couple max. Puis faites le revenir automatiquement à la position de départ.




