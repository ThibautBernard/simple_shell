#include "holberton.h"

/**
 * _help - display descriptions of builtin
 * @n: integer
 * @s: array of array of arguments
 * @node: linked list of environment
 * Return: 1 success or 0
 */
int _help(int n, char **s, envNodes **node)
{
	(void)n;
	(void)node;
	char *arr1[] = {"env", "setenv", "unsetenv", "exit", "cd", NULL};
	char *arr2[] = {"env - Print the environment\n", "setenv [variable] [value] - Initialize or update variable of environment\n",
	"unsetenv [variable] - Remove variable in the environments\n",
	"exit [status] - Exit all the process\n", "cd - change directory\n", NULL};
	char *tmp;
	int i = 0;

	while (s[i])
		i++;
	tmp = s[1];
	if (i == 1)
	{
		i = 0;
		while (arr1[i])
		{
			write(STDOUT_FILENO, arr2[i], _strlen(arr2[i]));
			i++;
		}
		return (1);
	}
		i = 0;
		while (arr1[i])
		{
			if (_strncmp(tmp, arr1[i], _strlen(tmp)) == 0)
			{
				write(STDOUT_FILENO, arr2[i], _strlen(arr2[i]));
				return (1);
			}
			i++;
		}
	return (0);
}
