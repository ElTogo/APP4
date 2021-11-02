/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE]="teste.txt";
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

	// exemple d'appel de fonction
	
    retour = pgm_lire(nom, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);

	
	
	printf("\n");

	// autre exemple d'appel de fonction
    pgm_ecrire(nom, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees);

    printf("-> Fin!\n");

    return 0;
}
