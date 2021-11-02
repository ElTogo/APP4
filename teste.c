#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fichier;
    fichier = fopen("teste.txt", "r");
    if (fichier==NULL)
    {
		printf("erreur ouverture fichier\n");
		return (-1);
	}
	char c;
	fscanf(fichier,"%c",&c);
	
	if (c=='#')
	{
		char meta[100];
		fgets(meta, 100, fichier);
		printf("lecteures des meta donnees\n");
		char auteur[100];
		char date[100];
		char place[100];
		int compteurMeta = 0;
		int compteurString = 0;
		
		while (meta[compteurMeta]!=';')
		{
			auteur[compteurString] = meta[compteurMeta];
			compteurMeta+=1;
			compteurString+=1;
		}
		auteur[compteurString]='\0';
		printf("%s\n", auteur);
		compteurString=0;
		compteurMeta+=1;
		
		while (meta[compteurMeta]!=';')
		{
			date[compteurString] = meta[compteurMeta];
			compteurMeta+=1;
			compteurString+=1;
		}
		date[compteurString]='\0';
		printf("%s\n", date);
		compteurString=0;
		compteurMeta+=1;
		
		while (meta[compteurMeta]!='\n')
		{
			place[compteurString] = meta[compteurMeta];
			compteurMeta+=1;
			compteurString+=1;
		}
		place[compteurString]='\0';
		printf("%s\n", place);
		
	}
}
