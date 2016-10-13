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
On voit que le fichier est maintenant suivi.</br>
On peut maintenant valider les modifications effectuees (ici l'ajout d'un fichier) avec `git commit`</br>
Donnez un message de commit, par exemple "1er commit"</br>
Note : On aurait aussi pu faire `git commit -m "1er commit".

### Utilisation d'un depot distant
En general, on utilise un depot distant accessible par tous les participants du projet, par exemple sur Github au club ou sur Gitlab pour l'ecole.</br>
Ici, le depot que l'on vient de creer jouera le role de depot distant sur notre machine.</br>
Du coup, nous devons reconfigurer le depot en depot distant, pour cela, faites : 
```
git config --bool core.bare true
rm foo
```
Note : en pratique, vous n'aurez jamais a faire ca.</br>
Dans le dossier ExempleGit, creez un dossier 1erDepot et une dossier 2ndDepot.</br>
Dans chacun de ces dossiers, faites `git clone ../Distant .`</br>
Vous venez de creer deux nouveaux depots qui sont une copie du depot contenu dans Distant.</br>
Vous pouvez avoir un terminal ouvert pour chacun de ces deux nouveaux depots, cela sera plus pratique pour la suite.</br>
Ces deux depots representent deux utilisateurs travaillant ensemble sur un meme projet.</br>
Allez maintenant dans le premier depot et rajoutez une ligne contenant Bonjour dans le fichier foo :
```
Hello World
Bonjour
```
Faites `git status`</br>
On voit que le fichier a ete modifie.</br>
Faites un `git add` puis un `git commit`</br>
Note : Avec `git commit -a`, on cree un commit contenant tous les fichiers modifies (mais pas les nouveaux fichiers).</br>
On veut maintenant mettre a jour le depot distant, pour cela faites `git push`</br>
Pour remettre le 2nd depot a jour, dans 2ndDepot, faites `git pull`</br>
Vous pouvez verifier que le fichier foo a bien ete mis a jour.

### Un conflit
Dans 1er depot, ajoutez Buenos dias au fchier foo : 
```
Hello World
Bonjour
Buenos dias
```
Comme precedemment, pushez la modification sur le depot distant (il faut faire un commit avant)</br>
dans 2eme depot, ne mettez pas ajour mais ajoutez Guten Tag au fichier foo :
```
Hello World
Bonjour
Guten Tag
```
Pushez la modification.</br>
On voit qu'on n'a pas le droit de faire `git push`, si le depot distant a ete mis a jour, il faut faire `git pull` avant de pouvoir pusher.</br>
On voit que le pull a engendre un conflit dans le fichier foo, il faut donc resoudre ce conflit</br>
Pour cela, ouvrez le fichier foo</br>
Modifiez le pour obtenir ce resultat :
```
Hello World
Bonjour
Guten Tag
Buenos dias
```
Recommitez et pushez

### Bonnes pratiques
Commitez et pushez regulierement.</br>
Ne pushez que des fichiers texte, pas d'executables (sinon, impossible de resoudre les conflits par exemple).</br>
Pour cela, vous pouvez creer dans le dpot un fichier `.gitignore` qui contient les fichiers a ne pas commiter.</br>
Par exemple, on peut mettre `*.o` dans le .gitignore pour ignore tous les fichiers objets C.</br>
Creez un fichier bar contenant ce que vous voulez.</br>
Faites `git status`</br>
Creez un fichier .gitigonre contenant une ligne `bar`</br>
Refaites `git status`</br>
On voit que git ne tient plus compte du fichier bar.

### Guide de survie
Vous pouvez trouvez un guide de survie pour git un peu plus complet que ce cours [ICI](https://sen.enst.fr/se203/memento-git)
