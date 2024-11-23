#include "define et fonctions.h"

void placerBarriere(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur *joueur) {
    if (joueur->barrières_restantes <= 0) {
        printf("Vous n'avez plus de barrières.\n");
        return;
    }

    int x, y;
    char orientation;
    printf("Position de la barrière (x y orientation [H/V]) : ");
    scanf("%d %d %c", &x, &y, &orientation);

    // Convertir les coordonnées utilisateur vers les coordonnées internes du plateau
    int px = x * 2; // Coordonnée pour la barrière horizontale ou verticale
    int py = y * 2;

    if (orientation == 'H') { // Placement horizontal
        if (px >= 0 && px < TAILLE_PLATEAU && py >= 0 && py < TAILLE_PLATEAU && plateau[px][py] == ' ' && plateau[px][py + 1] == ' ') {
            plateau[px][py] = '-';  // Barrière horizontale
            plateau[px][py + 1] = '-';  // Barrière horizontale
            joueur->barrières_restantes--;
        } else {
            printf("Placement invalide !\n");
        }
    } else if (orientation == 'V') { // Placement vertical
        if (px >= 0 && px < TAILLE_PLATEAU && py >= 0 && py < TAILLE_PLATEAU && plateau[px][py] == ' ' && plateau[px + 1][py] == ' ') {
            plateau[px][py] = '|';  // Barrière verticale
            plateau[px + 1][py] = '|';  // Barrière verticale
            joueur->barrières_restantes--;
        } else {
            printf("Placement invalide !\n");
        }
    } else {
        printf("Orientation invalide ! Utilisez 'H' pour horizontal ou 'V' pour vertical.\n");
    }
}
