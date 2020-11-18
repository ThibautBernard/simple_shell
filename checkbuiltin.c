#include "holberton.h"

/**
 *_checkbuiltin - check if the commad is a built in
 * @b1: built in struct
 * @s: command to string
 * Return: 1 if found and 0 if not found.
 */
int _checkbuiltin(bui *b1, char *s)
{
	int i, length = 0;

	length = strlen(s);
	for (i = 0; b1[i].name; i++)
	{
		if (strncmp(b1[i].name, s, length) == 0)
			return (1);
	}
	return (0);
}

/**
 *_launchbuiltin - Launch a built in command
 * @b1: built in struct
 * @s: command to string
 * Return: 1 if execute if not 0
 */
int _launchbuiltin(bui *b1, char *s)
{
	int i, length = 0;

	length = strlen(s);
	for (i = 0; b1[i].name; i++)
	{
		if (strncmp(b1[i].name, s, length) == 0)
		{
			b1[i].f(98);
			return (1);
		}
	}
	return (0);
}
