#include<stdio.h>
#include<string.h>

main()
{
	char ch[100];
	start:
	printf("* Chaine palindrome:\n\n");
	printf("Entrez du texte: ");
	gets(ch);
	int i, j, n=0;
	char c;
	
	do {
		c = ch[n];
		if (c != '\0') n++;
	} while(c != '\0');
	//n = strlen(ch);
	
	printf("Longeur du texte: %d\n", n);
	
	for(i=0; i<n; i++)
	{
		if(ch[i] == ' ' || ch[i] == '\t')
		{
			for (j=i; j<n; j++)
			{
				ch[j] = ch[j+1];
			}
			i--;
			n--;
		}
	}
	printf("Votre texte sans espaces et tabulations:\n\t");
	printf(ch);
	
	char ch_b[100];
	strcpy(ch_b,ch);
	for(i=0; i<n/2; i++)
	{
			c = ch[i];
			ch[i] = ch[n-i-1];
			ch[n-i-1] = c;		
	}
	
	printf("\nVotre texte renverse:\n\t");
	printf(ch);
	
	if(strcmp(ch,ch_b) == 0)
	{
		printf("\nChaine palindrome.\n");
	} 
	else
	{
		printf("\nChaine NON palindrome.\n");
	}
	
	
	system("pause>null");
	system("cls");
	goto start;
}
