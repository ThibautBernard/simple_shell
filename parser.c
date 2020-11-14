#include "holberton.h"
/**
 * parseintab - parse a string
 * in function of delim into a char **
 * @str: string to parse
 * Return: NULL or the pointer of pointer
 */
char **parseintab(char *str)
{
	int i = 0, length_param = 0;
	char **av, *delim = " \n\r\t", *temp;
	length_param = getnbwords(str, " ");
	av = malloc(sizeof(char*)*(length_param + 1));
	if (av == NULL || str == NULL)
		return (NULL);
	temp = strtok(str, delim);
	while(temp)
	{
		av[i] = temp;
		temp = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	if (temp != NULL)
		free(temp);
	return (av);
}
