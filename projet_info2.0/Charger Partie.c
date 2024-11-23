#include "define et fonctions.h"

void chargerPartie(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[]) {
    FILE *f = fopen("sauvegarde.txt", "r");
    if (!f) {
        printf("Erreur de chargement.\n");
        return;
    }
    fread(plateau, sizeof(char), TAILLE_PLATEAU * TAILLE_PLATEAU, f);
    fread(joueurs, sizeof(Joueur), 2, f);
    fclose(f);
    printf("Partie chargée !\n");
}