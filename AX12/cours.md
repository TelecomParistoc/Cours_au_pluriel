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
  
 
## Qu'est-ce qu'un AX12 ?
 
[Datasheet](http://www.trossenrobotics.com/images/productdownloads/AX-12(English).pdf)
 
 
