#include "define et fonctions.h"

void initialiserPlateau(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            if (i % 2 == 0 || j % 2 == 0) {
                // Cases pour les barrières ou intersections
                plateau[i][j] = ' ';
            } else {
                // Cases jouables
                plateau[i][j] = '.';
            }
        }
    }

    // Placer les joueurs
    plateau[1][TAILLE_PLATEAU / 2] = '1';  // Joueur 1
    plateau[TAILLE_PLATEAU - 2][TAILLE_PLATEAU / 2] = '2';  // Joueur 2
}
