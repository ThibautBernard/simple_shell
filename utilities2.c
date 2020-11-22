#include "holberton.h"

/** _strdup - _strdup
 * @s: string to dup
 * Return: dupped string
 */

char *_strdup(char *s) 
{
	int i;
	char *tmp;

	tmp = malloc(sizeof(char) * (_strlen(s) + 1));
	if (tmp == NULL)
		return(0);

	for(i = 0; s[i]; i++)
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (tmp);
}
