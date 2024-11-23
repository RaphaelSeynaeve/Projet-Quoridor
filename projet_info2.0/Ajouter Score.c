#include "define et fonctions.h"

void ajouterScore(char *nom, int score) {
    FILE *f = fopen("scores.txt", "a");
    if (!f) {
        printf("Erreur d'enregistrement des scores.\n");
        return;
    }
    fprintf(f, "%s : %d\n", nom, score);
    fclose(f);
    printf("Score enregistré pour %s : %d points\n", nom, score);
}
