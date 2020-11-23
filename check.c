#include "holberton.h"

/**
 * check_sep - check if there is
 * ; or other
 * @argv: array of array of commands
 * Return: number of sep in array of array
 */
int check_sep(char **argv)
{
	int i = 0, counter = 0;

	while (argv[i])
	{
		if (_strncmp(argv[i], ";", 1) == 0)
			counter++;
		i++;
	}
	return (counter);
}
