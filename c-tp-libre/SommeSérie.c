#include<stdio.h>

main()
{
	int i, N=20, S=0, U=30;
	for(i=0; i<N; i++)
	{
		printf("[%d] + %d\n", i+1, U);
		S += U;
		U += 13;
	}
	printf("------------\n");
	printf("= %d\n", S);
	
	system("pause>null");
}
