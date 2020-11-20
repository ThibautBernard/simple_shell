#include <stdio.h>
#include <string.h>
#include "../holberton.h"
int main()
{
	char s[] = "          ls t";
	char s1[] = "          ls t";
	char *d = " \n\r\t";
	char *d1 = " \n\r\t";
	char *token;
	char *token2;

	token = _strtok(s, d);
	while (token)
	{
		printf("RESULT  =>%s\n",token);	
		token = _strtok(NULL, d);
	}
	token = _strtok(s, d);
	while (token)
	{
		printf("RESULT  =>%s\n",token);	
		token = _strtok(NULL, d);
	}
	printf ("seconde time \n");
	token2 = strtok(s1, d1); 
	while (token2)
	{
		printf("EXPECTED=>%s\n",token2);	
		token2 = strtok(NULL, d1);
	}
	token2 = strtok(s1, d1); 
	while (token2)
	{
		printf("EXPECTED=>%s\n",token2);	
		token2 = strtok(NULL, d1);
	}

	return (0);
}
