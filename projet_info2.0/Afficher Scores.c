#include "define et fonctions.h"

void afficherScores() {
    FILE *f = fopen("scores.txt", "r");
    if (!f) {
        printf("Pas de scores disponibles.\n");
        return;
    }
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), f)) {
        printf("%s", ligne);
    }
    fclose(f);
}
