/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

int extraireMetadonnees(struct MetaData *p_metadonnees, char meta[MAX_CHAINE])
{
		int compteurMeta = 0;
		int compteurString = 0;
		
		while (meta[compteurMeta]!=';')
		{
			if (meta[compteurMeta]=='\0')
			{
				return -3;
			}
			p_metadonnees->auteur[compteurString] = meta[compteurMeta];
			compteurMeta+=1;
			compteurString+=1;
		}
		p_metadonnees->auteur[compteurString]='\0';
		compteurString=0;
		compteurMeta+=1;
		
		while (meta[compteurMeta]!=';')
		{
			if (meta[compteurMeta]=='\0')
			{
				return -3;
			}
			p_metadonnees->dateCreation[compteurString] = meta[compteurMeta];
			compteurMeta+=1;
			compteurString+=1;
		}
		p_metadonnees->dateCreation[compteurString]='\0';
		compteurString=0;
		compteurMeta+=1;
		
		while (meta[compteurMeta]!='\0')
		{
			if (meta[compteurMeta]==';')
			{
				return -3;
			}
			p_metadonnees->lieuCreation[compteurString] = meta[compteurMeta];
			compteurMeta+=1;
			compteurString+=1;
		}
		p_metadonnees->lieuCreation[compteurString]='\0';
		return 0;
}

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    int validation = 0;
    FILE *fichier;
    fichier = fopen(nom_fichier, "r");
    if (fichier==NULL)
    {
		return (-1);
	}
	
	char premierCaractere;
	fscanf(fichier, "%c", &premierCaractere);
		
	if (premierCaractere=='#')
	{
		char buffer[(MAX_CHAINE*3+2)];
		fgets(buffer, MAX_CHAINE*3+2, fichier);
		validation = extraireMetadonnees(p_metadonnees, buffer);
		printf("%i", validation);
		if (validation != 0){return validation;}
	}
	else {rewind(fichier);}
	
	
	
	
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    return OK;
}
