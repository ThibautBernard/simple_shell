#include "holberton.h"


/**
 * _strncmp - compare two string
 * @s1: string compare to s2
 * @s2: string compared with s1
 * @nb: length to compare
 * Return: negative number, positive, 0
 */
int _strncmp(const char *s1, char *s2, int nb)
{
	int i = 0, count = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && count < nb)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (-(s2[i] - s1[i]));
		i++;
		count++;
	}
	return (0);
}
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
 * @s: String to print
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
char *_concat(char *src, char *dest, char delim)
{
	char *concat;
	int len;
	int i;
	int j;

	len = (_strlen(src) + _strlen(dest) + 1);
	concat = malloc(sizeof(char) * len + 1);
	if (concat == 0)
		return (0);

	for (i = 0; src[i]; i++)
		concat[i] = src[i];
	concat[i] = delim;
	i++;
	for (j = 0; dest[j]; j++)
	{
		concat[i] = dest[j];
		i++;
	}
	concat[i] = '\0';

	return (concat);
}
