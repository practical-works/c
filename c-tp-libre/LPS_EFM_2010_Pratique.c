#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

struct date
{
	int jour;
	char mois[100];
	int annee;
};

void afficher_date(struct date dp)
{
	printf("\t%d %s %d", dp.jour,dp.mois,dp.annee);
}

void afficher_tous(struct date d[], int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		afficher_date(d[i]);
	}
}

void demander_date(struct date *dp)
{
	int ok;
	do {
		ok = TRUE;
		printf("Entrez jour: "); scanf("%d", &(*dp).jour);
		if((*dp).jour<1 || (*dp).jour>31) ok = FALSE;
		printf("Entrez mois: "); scanf("%s", (*dp).mois);
		if(numero_mois((*dp).mois) == -1) ok = FALSE;
		printf("Entrez annee: "); scanf("%d", &(*dp).annee);
		if((*dp).annee<1) ok = FALSE;
		if(ok == FALSE) printf("Date incorrecte!\n");
	} while(ok == FALSE);
}

void demander_tous(struct date d[], int *N)
{
	int i;
	printf("Entrez taille liste: "); scanf("%d",&(*N));
	for(i=0; i<*N; i++)
	{
		demander_date(&d[i]);
	}
}

void supprimer_date(struct date* dp)
{
	dp = NULL;
}

int numero_mois(char* nom_mois)
{
	int i;
	char str[100];
	strcpy(str, nom_mois);
	for(i=0; i<strlen(str); i++)
	{
		tolower(str[i]);
	}
		if( strcmp("janvier",str) == 0 ) return 1;
		else if( strcmp("fevrier",str) == 0 ) return 2;
		else if( strcmp("mars",str) == 0 ) return 3;
		else if( strcmp("avril",str) == 0 ) return 4;
		else if( strcmp("mai",str) == 0 ) return 5;
		else if( strcmp("juin",str) == 0 ) return 6;
		else if( strcmp("juillet",str) == 0 ) return 7;
		else if( strcmp("aout",str) == 0 ) return 8;
		else if( strcmp("septembre",str) == 0 ) return 9;
		else if( strcmp("octobre",str) == 0 ) return 10;
		else if( strcmp("novemebre",str) == 0 ) return 11;
		else if( strcmp("decemebre",str) == 0 ) return 12;
		else return -1;
}

int comparer_dates(struct date d1, struct date d2)
{
	if(d1.annee > d2.annee) return 1;
	else if(d1.annee < d2.annee) return -1;
	else 
	{
		if(numero_mois(d1.mois) > numero_mois(d2.mois)) return 1;
		else if(numero_mois(d1.mois) < numero_mois(d2.mois)) return -1;
		else
		{
			if(d1.jour > d2.jour) return 1;
			else if(d1.jour < d2.jour) return -1;
			else return 0;
		}
	}
}

int enregister_dates(struct date d[], int N, char* nom_fichier)
{
	FILE* fichier = NULL;
	fichier = fopen(nom_fichier,"w");
	if(fichier == NULL)
	{
		return 0;
	}
	else
	{
		pri
		int i;
		for(i=0; i<N; i++)
		{
			fprintf(fichier,"%d %s %d\n",d[i].jour,d[i].mois,d[i].annee);
		}
		fclose(fichier);
		return 1;
	}
}

int lire_dates(struct date d[], int Nmax, char* nom_fichier)
{
	FILE* fichier = NULL;
	fichier = fopen(nom_fichier, "r");
	if(fichier == NULL)
	{
		return 0;
	}
	else
	{
		int i = 0;
		while(!feof(fichier) || i<=Nmax)
		{
			fscanf(fichier,"%d %s %d",&d[i].jour,d[i].mois,&d[i].annee);
			i++;
		}
		fclose(fichier);
		return i-1;
	}
}

int trier_dates(struct date d[], int N)
{
	int i,j, tri = FALSE;
	struct date tmp;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1; j<N; j++)
		{
			if(comparer_dates(d[i],d[j]) < 0)
			{
				tmp = d[i];
				d[i] = d[j];
				d[j] = tmp;
				tri = TRUE;
			}
		}
	}
	return tri;
}

int main()
{
	int c, N;
	struct date D[100];
	do {
		system("cls");
	    printf("1 : Saisir une liste des dates\n");
		printf("2 : Lire une liste des dates à partir d’un fichier\n");
		printf("3 : Ajouter une date\n");
		printf("4 : Supprimer une date\n");
		printf("5 : Rechercher une date\n");
		printf("6 : Enregistrer les dates dans un fichier\n");
		printf("7 : Trier les dates\n");
		printf("8 : Quitter le programme\n");
		printf("\tEntrez votre choix [1-9] : ");
		scanf("%d",&c);
		printf("\n--------------\n");
		switch(c)
		{
			case 1: // Saisir une liste des dates
				 printf("Saisir une liste des dates:\n");
				 demander_tous(D,&N); 
				 afficher_tous(D,N); 
				 break; 
			case 2: // Lire une liste des dates à partir d’un fichier
				 printf("Lire une liste des dates à partir d’un fichier:\n");
				 printf("Entrez nom fichier:");
				 char f[100];
				 gets(f);
				 lire_dates(D,N,f);
				 afficher_tous(D,N);
				 break; 					
			case 3:  // Ajouter une date
				 printf("Ajouter une date:\n");
		 	 	 int p;
		 	 	 do {
			 	 	 	printf("Entrez position [1-%d]", N);
					 	scanf("%d", &p);
					 	p--;
					 	if(p<0 || p>N-1) printf("Position invalide!\n");
			   		} while(p<0 || p>N-1);
		   	     demander_date(&D[p]);	
				 afficher_tous(D,N); break; 				   
			case 4: // Supprimer une date 
				 printf("Supprimer une date:\n");
 	 			 int i;
		 	 	 do {
			 	 	 	printf("Entrez position [1-%d]", N);
					 	scanf("%d", &p);
					 	p--;
					 	if(p<0 || p>N-1) printf("Position invalide!\n");
			   		} while(p<0 || p>N-1);
	   			 supprimer_date(&D[p]);
   			 	 for(i=0; i<N; i++)
   			 	 {
   			 	 	if(i == p)
   			 	 	{
   			 	 		int j;
   			 	 		for(j=p; j>N; j++)
   			 	 		{
   			 	 			D[j] = D[j+1];
			 			}
		 		    }
				 }
				 N--;
				 afficher_tous(D,N); 
				 break;                   
			case 5: // Rechercher une date 
				 printf("Rechercher une date:\n");
				 
				 afficher_tous(D,N); break;                  
			case 6:  afficher_tous(D,N); break;                 // Enregistrer les dates dans un fichier
			case 7:  afficher_tous(D,N); break;                // Trier les dates
			case 8: break;                                    // Quitter
			default: printf("Choix invalide!\n");
		}
	} while(c != 9);
}
