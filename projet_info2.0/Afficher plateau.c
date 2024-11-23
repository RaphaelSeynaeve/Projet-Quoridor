#include "define et fonctions.h"
#include <stdio.h>

// Couleurs ANSI
#define RESET "\033[0m"
#define NOIR "\033[40m"
#define BLANC "\033[47m"
#define ROUGE "\033[41m"
#define VERT "\033[42m"
#define JAUNE "\033[43m"
#define BLEU "\033[44m"
#define GRIS "\033[100m"


void afficherPlateau(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    printf("  ");
    for (int j = 0; j < TAILLE_PLATEAU; j++) {
        if (j % 2 == 1) {
            printf("%d", j / 2); // Numérotation des colonnes
        } else {
            printf("   ");
        }
    }
    printf("\n");

    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (i % 2 == 0) {
            printf("    ");
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                if (j % 2 == 0) {
                    printf("+"); // Intersection des lignes
                } else if (plateau[i][j] == '-') { // Barrière horizontale
                    printf("%s---%s", ROUGE, RESET);
                } else {
                    printf("   "); // Espaces vides
                }
            }
            printf("\n");
        } else {
            printf(" %d  ", i / 2); // Numérotation des lignes
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                if (j % 2 == 0) { // Barrière verticale ou espace
                    if (plateau[i][j] == '|') {
                        printf("%s|%s", ROUGE, RESET); // Barrière verticale
                    } else {
                        printf(" ");
                    }
                } else { // Case jouable
                    if (plateau[i][j] == '1') {
                        printf("%s 1 %s", VERT, RESET);
                    } else if (plateau[i][j] == '2') {
                        printf("%s 2 %s", JAUNE, RESET);
                    } else {
                        printf("%s . %s", GRIS, RESET);
                    }
                }
            }
            printf("\n");
        }
    }
}


