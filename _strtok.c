#include "holberton.h"
/**
 * checkdelim - check if a character is in a string)
 * @c: char to check
 * @delim: delimiter to check(every char is a different delimiter)
 * Return: return 1 if it s a delimiter
 */

int checkdelim(char c, const char *delim)
{
	int i;

	for (i = 0; delim[i]; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}

/**
 *_strtok - parse a string depending of a delimiter
 * @str: string to check
 * @delim: delimiter to check(every char is a different delimiter)
 * Return: pointer the begning of a word
 */
char *_strtok(char *str, const char *delim)
{
	static char *PTR;
	char *ptr2;/*begining*/
	char c, c1;

	if (str != NULL)
		PTR = str;
	c = PTR[0];
	while (checkdelim(c, delim) == 1)
	{
		PTR++;
		c = PTR[0];
	}
	if (PTR[0] == '\0')
		return (NULL);
	ptr2 = PTR;
	while (checkdelim(c, delim) == 0 && c != '\0')
	{
		PTR++;
		c = PTR[0];
	}
	if (c == '\0')
		return (ptr2);
	if (checkdelim(c, delim) == 1)
	{
		*PTR = '\0';
		PTR++;
		c = PTR[0];
		c1 = PTR[1];
	}
	while (checkdelim(c, delim)  == 1 && checkdelim(c1, delim))
	{
		PTR++;
		c = PTR[0];
		c1 = PTR[1];
	}
	if (checkdelim(c, delim) == 1 && checkdelim(c1, delim) == 0)
		PTR++;
	return (ptr2);
}
