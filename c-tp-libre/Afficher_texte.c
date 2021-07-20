#include<stdio.h>
main()
{
	FILE* f;
	f = fopen("quotes.txt","r");
	if (!f)
	{
		printf("/!\\n");
	}
	else
	{
		char c;
		do
		{
  		    c = fgetc(f);
			sleep(0.007);
			putchar(c);
		} while (!feof(f));
	}
	getchar();
}
