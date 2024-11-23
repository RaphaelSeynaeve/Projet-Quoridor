cmake_minimum_required(VERSION 3.29)
project(projet_info2_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(projet_info2_0
        "define et fonctions.h"
        menu.c
        "Initialiser plateau.c"
        "Afficher plateau.c"
        "Déplacer Joueur.c"
        "Placer Barrière.c"
        "Sauvegarder Partie.c"
        "Charger Partie.c"
        "Afficher Scores.c"
        "Ajouter Score.c"
        main.c
        NouvellePartie.c
        "Initialiser Joueurs .c"
)
