#include "holberton.h"

/**
 *_strlen - _strlen
 * @s: the string to get size
 * Return: On success size
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - writes all the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstr(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		_putchar(s[i]);

	return (0);
}
/**
 * _concat - concat two string
 * @src: string 1
 * @dest: string 2
 * Return: a new string
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_concat(char *src, char *dest)
{
	char *concat;
	int len;
	int i;
	int j;

	len = (_strlen(src) + _strlen(dest));
	concat = malloc(sizeof(char) * len + 1);
	if (concat == 0)
		return (0);

	for (i = 0; src[i]; i++)
		concat[i] = src[i];
	for (j = 0; dest[j]; j++)
	{
		concat[i] = dest[j];
		i++;
	}
	concat[i] = '\0';

	return (concat);
}
