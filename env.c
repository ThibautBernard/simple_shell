#include "holberton.h"
/**
 *_strlen_const - _strlen
 * @s: the string to get size
 * Return: On success size
 */
int _strlen_const(const char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * _getenv - get value of env variable
 * @name: name of the variable
 * Return: string to the value or NULL
 */
char *_getenv(const char *name)
{
	int i = 0, x = 0, l, length_name = 0, length_env = 0;
	char *tmp;

	if (name == NULL)
		return (NULL);
	length_name = _strlen_const(name);
	while (environ[i])
	{
		if (_strncmp(name, environ[i], length_name) == 0)
		{
			length_env = _strlen(environ[i]);
			tmp = malloc(sizeof(char) * (length_env - length_name));
			if (tmp == NULL)
			{
				perror("Error getenv");
				return (NULL);
			}
			l = (length_name + 1);
			while (environ[i][l])
			{
				tmp[x] = environ[i][l];
				l++;
				x++;
			}
			tmp[x] = '\0';
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
/**
 * print_env - print the environnement
 * @n: nothing
 * Return: nothing
 */
int print_env(int n)
{
	int i = 0;

	while (environ[i])
	{
		_putstr(environ[i]);
		_putstr("\n");
		i++;
	}
	return (n);
}
