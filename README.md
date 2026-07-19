# Exercices de programmation

Recueil de mes exercices d'apprentissage en C, C++ et Python, développés dans le cadre de mon apprentissage en autodidacte

Ce ne sont pas des projets aboutis mais des exercices de progression à l'exception de PirateQuest, un petit jeu complet que j'ai poussé un peu plus loin.

## C

Deux fichiers repris de mes fiches de révision : les bases du langage (variables, boucles, pointeurs, structures, fichiers) puis un focus sur la mémoire dynamique (`malloc`, `realloc`, `calloc`, tableaux 2D, libération mémoire).

Compilation :
```
gcc -o programme 01-bases-c.c
```

## Cpp

Onze fichiers qui suivent ma progression en C++, des bases (conditions, boucles) jusqu'à la programmation orientée objet (structures, constructeurs, destructeurs, classes). Chaque fichier se compile indépendamment :
```
g++ -std=c++17 -o programme 09-constructeurs.cpp
```

## Python

- **jeux/snake.py** : le jeu snake classique, fait avec `turtle`.
- **asyncio/** : deux exemples pour comprendre `async`/`await` (envoi de messages en parallèle, requête HTTP asynchrone avec `aiohttp`).
- **manim-animations/** : petites animations faites avec [Manim](https://www.manim.community/).

Installation (dans chaque sous-dossier qui contient un `requirements.txt`) :
```
pip install -r requirements.txt
python nom_du_fichier.py
```

## Projects/pirate-quest

Un petit jeu complet fait avec Pygame, construit sur une carte Tiled (`.tmx`) : trois îles séparées par la mer, chacune cachant un coffre au trésor. Le déplacement se fait à pied sur la terre, et en bateau pour traverser l'eau et rejoindre les autres îles.

**Contrôles**
- Flèches ou ZQSD : se déplacer
- E : embarquer / débarquer du bateau
- Échap : quitter

**Lancer le jeu**
```
cd Projects/pirate-quest
pip install -r requirements.txt
python game.py
```

Fait avec `pygame`, `pytmx` et `pyscroll` pour le rendu de la carte et le défilement de la caméra.

## Auteur

**Yassine El Yazami** — Étudiant en Automatisation (EPHEC TECH)