#include<stdio.h>
#include<string.h>

main()
{
	int i,j, N, T[100], nombre;
	printf("[*] Taille Tableau: "); scanf("%d", &N); puts("");
	for(i=0; i<N; i++)
	{
		printf("\t[ %d ] <-- ", i); scanf("%d", &T[i]);
	}
	puts("");
	int nombre_existe = 1;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(T[j] % T[i] == 0)
			{
				printf("\t[ %d ] %d divise %d \n", i, T[j],T[i]);
			}
			else
			{
				printf("\t[ %d ] %d ne divise pas %d \n", i, T[j],T[i]);
				nombre_existe = 0;
			}
		}
		if(nombre_existe = 1) { nombre = T[i]; break; }
		else nombre = 0;
	}
	if(nombre == 0) printf("Pas de solution!\n");
	else printf("Le nombre recherché est %d, car il divise toutes les autres valeurs.\n", nombre);
	system("pause>null");
}

