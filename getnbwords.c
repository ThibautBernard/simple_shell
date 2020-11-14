#include "holberton.h"
/**
 * _ischar - _ischar
 * @c: check if a char
 * Return: On success size
 */

int _ischar(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * getnbwords - getnbwords
 * @str: string of str
 * @d: string of delimiter
 * Return: On success size
 */

int getnbwords(char *str, char *d)
{
	int i;
	int cp;
	int b;

	i = 0;
	cp = 0;
	if (_ischar(str[0]) == 1)
		cp++;
	while (str[i])
	{
		if ((str[i] == d[0]) && _ischar(str[i + 1]))
			cp++;
		i++;
	}
	return (cp);
}
