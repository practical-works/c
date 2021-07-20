#include<stdio.h>
#include<math.h>

int max_id(int T[], int N)
{
	int i, max = T[0], p;
	for(i=0; i<N; i++)
	{
		if(T[i] >= max)
		{
			max = T[i];
			p = i;
		}
	}
	return p;
}

int* tab_trie(int T[], int N)
{
}

main()
{
	int tab[100], i, p, ps, N=5, max;
	A:
	for(i=0; i<N; i++)
	{
	  	printf("\t[%d] Entrez valur: ", i); scanf("%d", &tab[i]);	
	}
	printf("\n===========================\n");
	for(i=0; i<N; i++)
	{
	  	printf("\t%d\n", tab[i]);	
	}
	printf("---------------------------\n");
	p = max_id(tab,N);
	printf("\tMax: %d", tab[p]);
	printf("\n---------------------------\n");
	max = tab[0];
	for(i=0; i<N; i++)
	{
		if(tab[i] != tab[p] && tab[i] >= max)
		{
			ps = i;
		}
	}
	printf("\tSous-Max: %d", tab[ps]);
	printf("\n---------------------------\n");
	
	system("pause>null");
	system("cls");
	goto A;
}
