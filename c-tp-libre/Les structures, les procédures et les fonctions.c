#include<stdio.h>
struct date
{
	int jour, mois, annee;
};
struct etudiant
{
	char nom[100], prenom[100];
	struct date date_naiss;
	float note[3], moyenne;
};
void lire_etudiant(struct etudiant E[], int *N)
{
	int i;
	printf("Entrez nombre etudiants: ");
	scanf("%d",&(*N));
	for(i=0; i<*N; i++)
	{
		printf("Entrez etudiant %d:\n", i+1);
		printf("Nom: "); scanf("%s", E[i].nom);
		printf("Prenom: "); scanf("%s", E[i].prenom);
		printf("Date Naissance:\n");
		printf("\tJour: "); scanf("%d", &E[i].date_naiss.jour);
		printf("\tMois: "); scanf("%d", &E[i].date_naiss.mois);
		printf("\tAnnee: "); scanf("%d", &E[i].date_naiss.annee);
		printf("Note 1: "); scanf("%f", &E[i].note[0]);
		printf("Note 2: "); scanf("%f", &E[i].note[1]);
		printf("Note 3: "); scanf("%f", &E[i].note[2]);
		E[i].moyenne = (E[i].note[0]+E[i].note[1]+E[i].note[2])/3;
		printf("Moyenne: %.2f\n", E[i].moyenne); 
	}
}
char* top_moy(struct etudiant E[], int N)
{
	int i, p;
	float top_moy = E[0].moyenne;
	for(i=0; i<N; i++)
	{
		if(E[i].moyenne >= top_moy)
		{
			top_moy = E[i].moyenne;
			p = i;
		}
	}
	return E[p].nom;
}
char* mention(struct etudiant E)
{
	float m = E.moyenne;
	if(m<10) return "Ajourne";
	else if(m<13) return "Admis";
	else if(m<16) return "A.Bien";
	else if(m<18) return "Bien";
	else return "T.Bien";
}
main()
{
	struct etudiant etd[100];
	int i, count;
	A:
	lire_etudiant(etd, &count);
	printf("%s a la meilleure moyenne.\n", top_moy(etd,count));
	for(i=0; i<count; i++)
	{
		printf("%s %s a une mention %s.\n", etd[i].nom, etd[i].prenom, mention(etd[i]));
	}
	system("pause>null");
	system("cls");
	goto A;
}
