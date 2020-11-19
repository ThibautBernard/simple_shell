#include <stdio.h>
#include <string.h>
#include "../holberton.h"
int main()
{
	char s[] = "a bateau:c";
	char *d = " :";
	char *token;

	token = _strtok(s, d); 
	printf("%s\n", token);
	token = _strtok(NULL, d); 
	printf("%s\n", token);
	token = _strtok(NULL, d); 
	printf("%s\n", token);
	token = _strtok(NULL, d); 
	printf("%s\n", token);

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
