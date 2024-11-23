#include "define et fonctions.h"
#include <stdio.h>
#include <stdlib.h>

void deplacerJoueur(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[2], Joueur *joueur) {
    int newX, newY;
    int dx, dy;
    int valide = 0;

    while (!valide) {
        // Afficher la demande de déplacement
        printf("Nouvelle position (x y) : ");
        scanf("%d %d", &newX, &newY);

        // Calcul des différences entre la position actuelle et la nouvelle
        dx = abs(newX - joueur->x);
        dy = abs(newY - joueur->y);

        // Vérifier que le déplacement est dans les limites du plateau
        if (newX < 0 || newX >= TAILLE_PLATEAU || newY < 0 || newY >= TAILLE_PLATEAU) {
            printf("Déplacement en dehors du plateau ! Essayez encore.\n");
            continue;
        }

        // Vérifier que la case cible est libre (case avec un point)
        if (plateau[newX][newY] != '.') {
            printf("La case cible est occupée ou invalide. Essayez encore.\n");
            continue;
        }

        // Vérifier si le déplacement est valide (cases adjacentes ou saut)
        if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1)) {
            // Déplacement simple (une case adjacente)
            valide = 1;
        } else if ((dx == 2 && dy == 0) || (dx == 0 && dy == 2)) {
            // Saut par-dessus un joueur
            int midX = (joueur->x + newX) / 2;
            int midY = (joueur->y + newY) / 2;

            // Vérifier qu'il y a bien un joueur entre les deux cases et que la case de saut est libre
            if ((plateau[midX][midY] == '1' || plateau[midX][midY] == '2') && plateau[newX][newY] == '.') {
                valide = 1;
            } else {
                printf("Impossible de sauter, la case de saut n'est pas libre.\n");
            }
        } else {
            printf("Déplacement invalide ! Essayez encore.\n");
        }
    }

    // Effectuer le déplacement
    plateau[joueur->x][joueur->y] = '.'; // Vider l'ancienne case
    joueur->x = newX; // Mettre à jour les coordonnées du joueur
    joueur->y = newY;
    plateau[newX][newY] = (joueur == &joueurs[0]) ? '1' : '2'; // Placer le joueur sur la nouvelle case
    printf("Nouvelle position : (%d, %d)\n", joueur->x, joueur->y);

    afficherPlateau(plateau);
}
