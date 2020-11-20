#include <stdio.h>
#include <string.h>
#include "../holberton.h"
int main()
{
	char s[] = "a bateau:c";
	char *d = " :";
	char *token;
	int i;

	token = _strtok(s, d); 
	while (token)
	{
		printf("%s\n",token);	
		token = _strtok(NULL, d);
	}
	/*("\n", token);
	token = strtok(NULL, d);
	printf("%s\n", token);
	token = strtok(NULL, d);
	printf("%s\n", token);
	token = strtok(NULL, d);
	printf("%s\n", token);
	    token = strtok(NULL, d);
		printf("%s\n", token);
	   */
	return (0);
}
