#include<stdio.h>
#include<string.h>
struct date
{
	int jour;
	char mois[100];
	int annee;
};
void Initialiser(struct date d[], int N)
{
	int i;
	for (i=0; i<N; i++)
	{
		d[i].jour = 17+i;
		strcpy(d[i].mois,"Juin");
		d[i].annee = 2016;
	}
}
int main(int argc, char const *argv[])
{
	int i, N = 10;
	struct date d[100];
	Initialiser(d,N);
	FILE* fichier;
	fichier = fopen("fichier.txt","w");
	if (!fichier)
	{
		printf("Fichier inaccessible!\n");
	}
	else
	{
		printf("Fichier ouvert en ecriture ...\n\n");
		for (i = 0; i < N; i++)
		{
			fprintf(fichier, "%d-%s-%d\n", d[i].jour, d[i].mois, d[i].annee);
			printf("\tCase %d sauvegardee!\n", i);
		}
		printf("\nSauvegarde termine.\n\n");
		fclose(fichier);
		printf("Fichier ferme.");
		system("start fichier.txt");
	}
	system("pause>null");
}
