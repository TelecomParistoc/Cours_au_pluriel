# Cours au pluriel
Introduction à la programmation pour la robotique.

## Avant tout

### Github <3

Créez un compte github, parce que github c'est cool (et que ça vous servira forcément).

### Atom

Pour ceux qui utilisent encore Eclipse, Code::Blocks ou autre monstre de lourdeur, ou ceux qui n'ont que gedit, [Atom est un excellent éditeur](https://atom.io) créé par github.


### Paire de clés

Pour se connecter au Raspberry Pi et utiliser git sans jamais devoir entrer le mot de passe, il vous faut une paire de clés.

Vérifier d'abord que vous n'en avez pas déjà :

```bash
ls ~/.ssh
```

Si vous avez un/des fichier(s) genre id_*sa.pub, vous avez déjà une paire de clés, inutile d'en créer une.

Pour créer une paire de clé (mettez votre email) :

```bash
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

Vous pouvez mettre une passphrase si ça vous chante, mais sachez qu'elle vous sera demandée de temps en temps quand vous utiliserez git ou ssh.

Ensuite il faut dire à ssh que vous voulez utiliser votre nouvelle clé. Assurez-vous que ssh-agent tourne :

```bash
eval "$(ssh-agent -s)"
```

puis (en remplaçant `id_rsa` par le nom de la clé, `id_rsa` est le défaut) :

```bash
ssh-add ~/.ssh/id_rsa
```

Enfin ajouter la clé publique à votre compte github (le contenu du fichier `id_rsa.pub`).

Et envoyez-moi cette même clé (publique !) pour que je vous ajoute aux Raspberry Pi, par mail à cle@bonetti.io.

*Note :* ne **JAMAIS** communiquer la clé privée.

## Ensuite

### [Bases du C](https://github.com/TelecomParistoc/Cours_au_pluriel/blob/master/C/cours.md)
par Julien ".js" Schoumacher

### [Git et Makefiles](https://github.com/TelecomParistoc/Cours_au_pluriel/blob/master/git/git.md)
par Tanguy "la blague" Rouffignac

### [Raspberry Pi et AX12](https://github.com/TelecomParistoc/Cours_au_pluriel/blob/master/AX12/cours.md)
par moi

## Pour ceux qui en savent déjà trop

### [Modélisation/impression 3D](https://github.com/TelecomParistoc/Cours_au_pluriel/blob/master/modelisation3D/cours.md)
par Sylvain "SLR" Le Roux
