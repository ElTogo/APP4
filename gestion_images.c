/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include <string.h>
#include "AutoValidation.h"
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
    char nom[MAX_CHAINE]="Sherbrooke_Frontenac_nuit.ppm";
    struct MetaData metadonnees;
	
    ppm_lire(nom, imageRGB1, &lignes1, &colonnes1, &maxval, &metadonnees);
    //pgm_extraire(image1, 50, 50, 70, 70, &lignes1, &colonnes1);
    //pgm_creer_negatif(image1, lignes1, colonnes1, maxval);
    //pgm_eclaircir_noircir(image1, lignes1, colonnes1, maxval, 1);
    //printf("%i %i", lignes1, colonnes1);
	//ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, 1);
	ppm_ecrire("teste.ppm", imageRGB1, lignes1, colonnes1, maxval, metadonnees);
	AutoValidation();
	
    return 0;
}
	
