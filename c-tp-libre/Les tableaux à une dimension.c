#include<stdio.h>

afficher(float T[], int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("\t%d) %.2f\n", i+1,T[i]);
	}
}
main()
{
	int i,j, n, existe, p;
	float x, tab[100];
	
	start:
	printf("Entrez taille tableau: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("%d) Entrez valeur: ", i+1);
		scanf("%f", &tab[i]);
	}
	
	afficher(tab,n);
	
	printf("Entrez valeur a rechercher: ");
	scanf("%f", &x);
	existe = 0;
	for(i=0; i<n; i++)
	{
		if(tab[i] == x)
		{
			existe = 1;
			p = i;
			break;
		}
	}
	if(existe == 1) printf("Valeur trouvee dans la postion %d (%d)\n", p, p+1);
	else 
	{
		printf("Valeur introuvable!\n");
		do {
			printf("Entrez position pour l'inserer (entre 0 et %d): ", n-1);
			scanf("%d", &p);
			if(p<0 || p>n-1) printf("Position invalide!\n");
		} while(p<0 || p>n-1);
		for(i=n; i>p; i--)
		{
			tab[i] = tab[i-1];
		}
		tab[p] = x;
		n++;
		
		afficher(tab,n);
	}
	
	printf("Entrez valeur a supprimer: ");
	scanf("%f", &x);
	existe = 0;
	for(i=0; i<n; i++)
	{
		if(tab[i] == x)
		{
			existe = 1;
			p = i;
			break;
		}
	}
	if(existe == 0) printf("Valeur introuvable!\n");
	else 
	{
		for(i=p; i<n; i++)
		{
			tab[i] = tab[i+1];
		}
		n--;
		printf("Valeur bien supprimee !\n");
	}
	
	afficher(tab,n);
	
	printf("Tableau trie par ordre decroissant: (Tri a bulle)\n");
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(tab[i] < tab[j])
			{
				x = tab[i];
				tab[i] = tab[j];
				tab[j] = x; 
			}
		}
	}	
	afficher(tab,n);
	
	printf("Tableau trie par ordre decroissant: (Tri a bulle optimise)\n");
	int echange = 0;
	j = i+1;
	for(i=0; i<n; i++)
	{
		while(j<n || echange==1)
		{
			echange = 0;
			if(tab[i] < tab[j])
			{
				x = tab[i];
				tab[i] = tab[j];
				tab[j] = x;
				echange = 1;
			}
			j++;
		}
	}	
	afficher(tab,n);
	
	system("pause>null");
	system("cls");
	goto start;
}
