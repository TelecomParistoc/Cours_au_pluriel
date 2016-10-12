# Git

### Introduction
Git est un logiciel de gestion de version, actuellement le plus utilise dans le Monde.</br>
Il permet de stocker les fichiers d'un projet ainsi que leurs versions anterieures et de travailler efficacement a plusieurs sur les memes fichiers.

### Installation
Ouvrez un terminal et tapez `git`.</br>
Si git n'est pas installe, tapez `sudo apt-get install git`.</br>
Maintenant, un peu de configuration :
```
git config --global user.name "Mon Nom"
git config --global user.email mon@email.example
git config --global core.editor monEditeurDeTextePrefere
``` 

### Creation d'un depot
Creez un dossier dans lequel on fera quelques exemples, par exemple un dossier ExempleGit dans Documents</br>
Dans ce dossier, creez un dossier Distant.</br>
Dans le dossier Distant, faites `git init`

### Un premier commit
Dans Distant, creez un fichier texte foo contenant une ligne Hello World.</br>
Faites `git status`</br>
Le fichier foo apparait normalement comme n'etant non suivi. On va l'ajouter au depot.</br>
Faites `git add foo`</br>
Note : On peut ajouter tous les fichiers dans le repertoire contenant le depot d'un seul coup avec `git add -A`</br>
Refaites `git status`</br>
On voit que le fichier est maintenant suivi</br>
On peut maintenant valider les modifications effectuees (ici l'ajout d'un fichier) avec `git commit`</br>
Donnez un message de commit, par exemple "1er commit"</br>
Note : On aurait aussi pu faire `git commit -m "1er commit"`

### Utilisation d'un depot distant
En general, on utilise un depot distant accessible par tous les participants du projet, par exemple sur Github au club ou sur Gitlab pour l'ecole.</br>
Ici, le depot que l'on vient de creer jouera le role de depot distant sur notre machine.</br>
Dans le dossier ExempleGit, creez un dossier 1erDepot et une dossier 2ndDepot.</br>
Dans chacun de ces dossiers, faites `git clone ../Distant .`</br>
Vous venez de creer deux nouveaux depots qui sont une copie du depot contenu dans Distant.</br>
Vous pouvez avoir un terminal ouvert pour chacun de ces deux nouveaux depots, cela sera plus pratique pour la suite.</br>
Ces deux depots representent deux utilisateurs travaillant ensemble sur un meme projet.
