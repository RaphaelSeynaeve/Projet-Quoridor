#include "define et fonctions.h"

void sauvegarderPartie(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[]) {
    FILE *f = fopen("sauvegarde.txt", "w");
    if (!f) {
        printf("Erreur de sauvegarde.\n");
        return;
    }
    fwrite(plateau, sizeof(char), TAILLE_PLATEAU * TAILLE_PLATEAU, f);
    fwrite(joueurs, sizeof(Joueur), 2, f);
    fclose(f);
    printf("Partie sauvegardée !\n");
}