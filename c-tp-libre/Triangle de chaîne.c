#include<stdio.h>
#include<string.h>
main()
{
	int i,j, N;
	char txt[100];
	printf("Entrez du texte: "); scanf("%s", txt); N = strlen(txt);
	for(i=0; i<N; i++)
	{
	 	for(j=0; i<i; i++)	 
		{
			printf("%c", txt[j]);
		}
		printf("\n");
	}
	
	system("pause>null");
}
