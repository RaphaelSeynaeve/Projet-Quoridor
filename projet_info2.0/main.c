#include <stdio.h>
#include <stdlib.h>
#include "define et fonctions.h"


int main() {
    char plateau[19][19];
    Joueur joueurs[2];
    int choix;
    int joueurActuel = 0; // Alternance des tours

    // Menu principal
    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Nouvelle partie
                // Initialisation de la partie
                nouvellePartie(plateau, joueurs);
                joueurActuel = 0; // Le joueur 1 commence

                int partieTerminee = 0;
                while (!partieTerminee) { // Boucle de jeu
                    afficherPlateau(plateau);
                    printf("Tour de %s\n", joueurs[joueurActuel].nom);
                    printf("1. Déplacer le pion\n");
                    printf("2. Placer une barrière\n");
                    printf("3. Sauvegarder et quitter\n");
                    printf("Choix : ");
                    int action;
                    scanf("%d", &action);

                    switch (action) {
                        case 1:
                            deplacerJoueur(plateau, joueurs, &joueurs[joueurActuel]);
                            break;
                        case 2:
                            placerBarriere(plateau, &joueurs[joueurActuel]);
                            break;
                        case 3:
                            sauvegarderPartie(plateau, joueurs);
                            partieTerminee = 1; // Quitter la boucle de jeu
                            break;
                        default:
                            printf("Action invalide.\n");
                    }

                    // Vérification de la victoire
                    if ((joueurActuel == 0 && joueurs[0].x == 8) || (joueurActuel == 1 && joueurs[1].x == 0)) {
                        printf("%s a gagné !\n", joueurs[joueurActuel].nom);
                        ajouterScore(joueurs[joueurActuel].nom, 5);
                        partieTerminee = 1; // La partie est terminée
                    }

                    // Changer de joueur
                    joueurActuel = (joueurActuel + 1) % 2;
                }
                break;

            case 2: // Charger une partie
                chargerPartie(plateau, joueurs);
                break;

            case 3: // Afficher les scores
                afficherScores();
                break;

            case 4: // Quitter
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
