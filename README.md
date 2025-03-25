# FdF

## Description

Le projet FdF (Fil de Fer) consiste à développer un programme en C capable de représenter en 3D une carte en fil de fer à partir d'un fichier contenant une grille de valeurs de hauteur. L'objectif est d'apprendre les bases de la programmation graphique avec la bibliothèque MiniLibX.

## Fonctionnalités

- Lecture et analyse de fichiers `.fdf` contenant des données de terrain
- Génération d'une représentation 3D en fil de fer du terrain
- Manipulation interactive de la vue : rotation, zoom, translation
- Gestion des couleurs selon l'altitude

## Prérequis

- Système d'exploitation : Linux ou macOS
- Compilateur C conforme à la norme C99
- Bibliothèque MiniLibX installée

## Installation

1. Cloner le dépôt :

```
git clone https://github.com/qbnt/2_FdF.git
cd 2_FdF
```

2. Compiler le projet :

```
make
```

## Utilisation

- Lancer le programme :

```
./fdf [chemin_du_fichier.fdf]
```

## 🗺️ Map Format

The map file is a plain text file where each line represents a row of elevation values (optionally with colors), e.g.:

```
0 0 0 0
0 1 1 0
0 0 0 0
```

Exemples de fichiers `.fdf` disponibles dans le dossier `maps`.

- Contrôles :
  - Flèches directionnelles : déplacer la vue
  - `+` / `-` : zoom avant/arrière
  - `W` / `S` : rotation axe X
  - `A` / `D` : rotation axe Y
  - `Q` / `E` : rotation axe Z
  - `ESC` : quitter

## Ressources Utiles

- [Documentation MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

## Licence

Projet sous licence MIT. Voir le fichier [LICENSE](LICENSE).


