/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include <string.h>
#include "bibliotheque_images.h"
int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int main()
{
    int lignes1, colonnes1;
    //int lignes2, colonnes2;
    int maxval;
    //int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE]="Sherbrooke_Frontenac_nuit.pgm";
    struct MetaData metadonnees;
	
    pgm_lire(nom, image1, &lignes1, &colonnes1, &maxval, &metadonnees); 
    strcpy(nom,"Sherbrooke_Frontenac_nuit_Copie.pgm");
	pgm_ecrire(nom, image1, lignes1, colonnes1, maxval, metadonnees);
    //pgm_extraire(image1, 50, 50, 70, 70, &lignes1, &colonnes1);
    //pgm_creer_negatif(image1, lignes1, colonnes1, maxval);
    pgm_eclaircir_noircir(image1, lignes1, colonnes1, maxval, -100);
	pgm_pivoter90(image1, &lignes1, &colonnes1, 1);
	pgm_ecrire(nom, image1, lignes1, colonnes1, maxval, metadonnees);
	
    return 0;
}
	
