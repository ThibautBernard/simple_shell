#include "holberton.h"

/**
 * _strdup - _strdup
 * @s: string to dup
 * Return: dupped string
 */
char *_strdup(char *s)
{
	int i;
	char *tmp;

	tmp = malloc(sizeof(char) * (_strlen(s) + 1));
	if (tmp == NULL)
		return (0);
	for (i = 0; s[i]; i++)
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (tmp);
}
/**
 *_mconcat - concatain source with destination
 * @src: source
 * @dest: destination
 * Return: resultat
 */

char *_mconcat(char *src, char *dest)
{
	int i;
	int j;
	char *res;

	res = malloc(sizeof(char) * (_strlen(src) + _strlen(dest) + 1));
	if (res == NULL)
		return (0);
	for (i = 0; src[i]; i++)
		res[i] = src[i];
	for (j = 0; dest[j]; j++)
	{   
		res[i] = dest[j];
		i++;
	}   
	res[i] = '\0';
	return (res);
}
