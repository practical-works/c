#include<stdio.h>
#include<string.h>
main()
{
	int i, * a;
	printf("Adresse \t| Valeur\n");
	printf("--------------------------\n");
	for(i=0; i<10; i++)
	{
		printf("%d \t| %d\n\n", &a+i, a);
	}
	
	
	
	
	system("pause>null");
}
