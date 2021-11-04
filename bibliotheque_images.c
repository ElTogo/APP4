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
		if (extraireMetadonnees(p_metadonnees, buffer) != 0)
		{
			return -3;
		}
	}
	else 
	{
		rewind(fichier);
		strcpy(p_metadonnees->auteur, "");
		strcpy(p_metadonnees->dateCreation, "");
		strcpy(p_metadonnees->lieuCreation, "");
	}
	
	char type[2];
	fscanf(fichier, "%s", type);
	if (type[1] != '2' || type[0]!='P')
	{
		return -3;
	}
	fscanf(fichier, "%i %i", p_colonnes, p_lignes);
	fscanf(fichier,"%i",p_maxval);
	if (*p_colonnes > MAX_HAUTEUR || *p_lignes > MAX_LARGEUR || *p_maxval > MAX_VALEUR)
	{
		return -2;
	}
	
	for (int i = 0; i < *p_colonnes; i++)
	{
		for (int j = 0; j< *p_lignes; j++)
		{
			fscanf(fichier, "%i", &matrice[i][j]);
		}
	}	
	return 0;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    FILE *fichier;
    fichier = fopen(nom_fichier, "w");
    if (fichier==NULL||colonnes>MAX_LARGEUR||lignes>MAX_HAUTEUR||maxval>MAX_VALEUR||colonnes<=0||lignes<=0||maxval<=0)
    {
		return (-1);
	}
	if (metadonnees.auteur[0]!='\0' || metadonnees.dateCreation[0]!='\0' || metadonnees.lieuCreation[0]!='\0')
	{
		fprintf(fichier, "#%s;%s;%s", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
	}
	
	fprintf(fichier, "P2\n");
	fprintf(fichier, "%i %i\n%i\n", colonnes, lignes, maxval);
	for (int i = 0; i<colonnes; i++)
	{
		for (int j = 0; j<lignes; j++)
		{
			fprintf(fichier, "%i ", matrice[i][j]);
		}
		fprintf(fichier, "\n");
	}
	return 0;
}

int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
{
	if (colonnes1>MAX_LARGEUR||lignes1>MAX_HAUTEUR||colonnes1<=0||lignes1<=0){return (-1);}
	p_lignes2=&lignes1;
	p_colonnes2=&colonnes1;
	
	for (int i = 0; i<colonnes1;i++)
	{
		for (int j = 0; j<lignes1;j++)
		{
			matrice2[i][j]=matrice1[i][j];
		}
	}
	return 0;
}

int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1])
{
	if (colonnes>MAX_LARGEUR||lignes>MAX_HAUTEUR||colonnes<=0||lignes<=0){return (-1);}
	
	for (int i = 0; i < MAX_VALEUR + 1; i++)
	{
		histogramme[i]=0;
	}
	
	for (int i = 0; i <colonnes; i++)
	{
		for (int j = 0; j < lignes; j++)
		{
			if (matrice[i][j]>MAX_VALEUR){return -1;}
			histogramme[matrice[i][j]]+=1;
		}
	}
	return 0;
}
int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes)
{
	int histogramme[MAX_VALEUR+1];
	if (pgm_creer_histogramme(matrice, lignes, colonnes, histogramme) != 0){return -1;}
	int couleur = 0;
	for (int i = 0; i < MAX_VALEUR + 1; i++)
	{
		if (histogramme[i]>histogramme[couleur])
		{
			couleur=i;
		}
	}
	return couleur;
}

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur)
{
int eclaircir_noircir = 0;
	for (int i = 0; i < colonnes; i++)
	{
		for (int j = 0; j < lignes; j++)
		{
			if (valeur < 0)
			{

				if (valeur < 0)
				{
					eclaircir_noircir = matrice[i][j] + valeur;
					if (eclaircir_noircir < 0)
					{
							return 0;
					}
					else
					{
						return eclaircir_noircir;
					}
				}
				if (valeur > 0)
				{
					eclaircir_noircir = matrice[i][j] + valeur;
					if (eclaircir_noircir > 256)
					{
						return 256;
					}
					else
					{
						return eclaircir_noircir;
					}
				}
			}
		}
	}
	return 0;
}

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval)
{
	for (int i = 0; i < colonnes; i++)
	{
		for (int j = 0; j < lignes; j++)
		{
			matrice[i][j] = maxval - matrice[i][j];
		}
	}
	return 0;
}

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes)
{
	for (int i = 0; i < (colonnes2); i++)
	{
		for (int j = 0; j < (lignes2); j++)
		{
			matrice[i][j] = matrice[(i+colonnes1)][(j+lignes1)];
		}
	}
	return 0;
}

int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	for (int i = 0; i <= colonnes1; i++)
	{
		for (int j = 0; j <= lignes1; j++)
		{
			for (int k = 0; k <= colonnes2; k++)
			{
				for (int h = 0; h <= lignes2; h++)
				{
					if (matrice1[i][j] == matrice2[k][h])
				}
			}
		}
	}
	return 0;
}

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)
{
	return 0;
}

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees)
{
	return 0;
}

int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees)
{
	return 0;
}

int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
{
	return 0;
}

int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	return 0;
}

int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)
{
	return 0;
}









