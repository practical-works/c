#include<stdio.h>
#include<string.h>
struct date
{
	int jour;
	char mois[100];
	int annee;
};
int main(int argc, char const *argv[])
{
	int i, N = 0;
	struct date d[100];
	FILE* fichier;
	fichier = fopen("fichier.txt","r");
	if (!fichier)
	{
		printf("Fichier inaccessible!\n");
	}
	else
	{
		printf("Fichier ouvert en lecture ...\n\n");
		while (!feof(fichier))
		{
			fscanf(fichier, "%d-%s[-]-%d", &d[N].jour, d[N].mois, &d[N].annee);
			printf("\tCase %d chargee!\n", N);
			N++;
		}
		N--;
		printf("\nCase %d vide eliminee!\n", N);
		printf("\nChargement termine.\n\n");
		fclose(fichier);
		printf("Fichier ferme.\n");
		printf("\n*--------------------------------*\n");
		printf("\tTableau extrait");		
		printf("\n*--------------------------------*\n");	
		printf(" #\tJour \tMois \tAnnee\n");
		printf("..................................\n");	
		for(i=0; i<N; i++)
		{
			printf(" [%d]\t%d \t%s \t%d\n", i, d[i].jour, d[i].mois, d[i].annee);
		}
		printf("*--------------------------------*\n");
	}
	system("pause>null");
}
