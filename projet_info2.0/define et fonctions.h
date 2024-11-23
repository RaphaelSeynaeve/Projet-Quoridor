#ifndef DEFINE_ET_FONCTIONS_H
#define DEFINE_ET_FONCTIONS_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define TAILLE_PLATEAU 19
#define JOUEUR1 '1'
#define JOUEUR2 '2'
#define VIDE '.'
#define BARRIERE_VERTICALE '|'
#define BARRIERE_HORIZONTALE '-'

typedef struct {
    char nom[50];
    int x, y; // Position sur le plateau
    int barrières_restantes;
} Joueur;

void initialiserJoueurs(Joueur joueurs[2]);
void nouvellePartie(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[2]);
void afficherPlateau(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
void initialiserPlateau(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
void afficherMenu();
void deplacerJoueur(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[2], Joueur *joueur);
void placerBarriere(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur *joueur);
void sauvegarderPartie(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[]);
void chargerPartie(char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU], Joueur joueurs[]);
void afficherScores();
void ajouterScore(char *nom, int score);


