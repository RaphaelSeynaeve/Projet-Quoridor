#include "define et fonctions.h"


void initialiserJoueurs(Joueur joueurs[2]) {
    printf("Nom du joueur 1 : ");
    scanf("%s", joueurs[0].nom);
    joueurs[0].x = 0; // Position de départ du joueur 1 (première ligne)
    joueurs[0].y = 4;

    printf("Nom du joueur 2 : ");
    scanf("%s", joueurs[1].nom);
    joueurs[1].x = TAILLE_PLATEAU - 1; // Dernière ligne valide
    joueurs[1].y = 4;
}
