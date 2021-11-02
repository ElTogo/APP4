/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

void extraireMetadonnees(MetaData *p_metadonnees, char string[MAX_CHAINE]
{
	int position1;
	int posistion2;
	int i = 0;
	
	while (string[i] != ';')
	{
		i+=1;
	}
	position1=i;
	i+=1;
	while (string[i] != ';')
	{
		i+=1;
	}
	position2=i;
	
	
}

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    FILE *fichier;
    fichier = fopen(nom_fichier[], "r");
    if (fichier==NULL)
    {
		return (-1);
	}

    if (fscanf(fichier,"%c")=="#");
    {
		
	}
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    return OK;
}
