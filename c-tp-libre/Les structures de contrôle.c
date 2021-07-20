#include<stdio.h>

main()
{
	int i, N, S;
	start:
	printf("* Nombre parfait:\n\n");
	do {
		printf("Entrez un nombre: ");
		scanf("%d", &N);
		if(N<=0)
		{
			printf("Vous devez entrer un entier naturel non nul!");			
		}
	} while (N<=0);
	
	S = 0;
	printf("\n");
	for(i=1; i<N; i++)
	{
		if(N%i == 0)
		{
			S += i;
			printf("%d est un diviseur de %d.\n", i,N);
		}
	}
	printf("\nLa somme des diviseurs de %d est: %d\n\n", N,S);
	if(S == N)
	{
		printf("%d est egal a la somme de ses diviseurs stricts.\n", N);
		printf("%d est un nombre parfait.\n", N);
	}
	else
	{
		printf("%d est different de la somme de ses diviseurs stricts!\n", N);
		printf("%d n'un pas nombre parfait.\n", N);
	}
	system("pause>null");
	system("cls");
	goto start;
}
