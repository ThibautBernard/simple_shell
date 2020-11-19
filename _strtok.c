#include "holberton.h"

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
	char c;
	int i;
	int b;

	if (str != NULL)
		PTR = str;
	ptr2 = PTR;
	c = PTR[0];
	b = 0;
	while (b == 0 && c != '\0')
	{
		for (i = 0; delim[i]; i++)
		{
			if (c == delim[i])
			{
				b = 1;
			}
		}
		if (b == 0)
			PTR++;
		c = PTR[0];
	}
	*PTR = '\0';
	PTR++;
	return (ptr2);
}
