#Git

### Introduction
Git est un logiciel de gestion de version, actuellement le plus utilise dans le Monde.
Il permet de stocker les fichiers d'un projet ainsi que leurs versions anterieures et de travailler efficacement a plusieurs sur les memes fichiers.

### Installation
Ouvrez un terminal et tapez `git`.
Si git n'est pas installe, tapez `sudo apt-get install git`.
Maintenant, un peu de configuration :
```
git config --global user.name "Mon Nom"
git config --global user.email mon@email.example
git config --global core.editor monEditeurDeTextePrefere
``` 

### Creation d'un depot
Creez un dossier dans lequel on fera quelques exemples, par exemple un dossier ExempleGit dans Documents
Dans ce dossier, creez un dossier Distant
Dans le dossier Distant, faites `git init`

### Un premier commit
Dans Distant, creez un fichier texte foo contenant une ligne Hello World.
Faites `git status`
Le fichier foo apparait normalement comme nétant non suivi. On va l'ajouter au depot.
Faites `git add foo`
Note : On peut ajouter tous les fichiers dans le repertoire contenant le depot d'un seul coup avec `git add -A`
Refaites `git status`
On voit que le fichier est maintenant suivi
On peut maintenant valider les modifications effectuees (ici l'ajout d'un fichier) avec `git commit`

### Utilisation d'un depot distant
En general, on utilise un depot distant accessible par tous les participants du projet, par exemple sur Github au club ou sur Gitlab pour l'ecole.
Ici, le depot que l'on vient de creer jouera le role de depot distant sur notre machine.
Dans le dossier ExempleGit, creez un dossier 1erDepot et une dossier 2ndDepot.
Dans chacun de ces dossiers, faites `git clone ../Distant .`
Vous venez de creer deux nouveaux depots qui sont une copie du depot contenu dans Distant.
Vous pouvez avoir un terminal ouvert pour chacun de ces deux nouveaux depots, cela sera plus pratique pour la suite.
Ces deux depots representent deux utilisateurs travaillant ensemble sur un meme projet.
