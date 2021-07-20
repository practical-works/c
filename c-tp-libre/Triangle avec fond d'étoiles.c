#include<stdio.h>
#include<string.h>
main()
{
	int i, j, N=5;
//	printf("Entrez un nombre: ");
//	scanf("%d", &N);
	for(i=N; i>0; i--)
	{
		for(j=0; j<i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	system("pause>null");
}
