L'afficheur TAMTAM 

# Installation de l'environnement de développement

## avec vscode

Installer le plugin vscode Arduino

Cloner le repo

Brancher le module ESP8266, il devrait être reconnu directement (en bas à droite dans la barre des taches (WeMos D1 R1))

Utiliser la palette de commandes (shift + cmd + P sous MacOs) et lancer Arduino:Initialize pour iniatiliser l'environnement arduino pour le projet.
La commande devrait créer le dossier .vscode à la racine du projet.

Avec la palette de commandes :
  - Arduino:Verify : pour vérifier (compiler) le sketch
  - Arduino:Upload : pour installer le projet sur la board arduino

# Configuration de l'environnement de développement

## Debug avec VSCODE

Par défaut, le projet est configuré pour utiliser Console qui utilise le Serial pour logger.

Dans src/adapters/console/console.h, decommenter #define DEBUG 1 pour afficher les logs et fixer le BAUDRATE
Dans la palette de commande, choisir Arduino:Open serial monitor

A l'upload, vscode devrait directement afficher le moniteur série.

## Wifi AP

#FIXME
Au lancement, l'access point s'appelle tamtam en dur dans le code

Une page web s'affiche pour configurer le tamtam
