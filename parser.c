#include "holberton.h"
/**
 * parseintab - parse a string
 * in function of delim into a char **
 * @str: string to parse
 * Return: NULL or the pointer of pointer
 */
char **parseintab(char *str)
{
	int i = 0, length_param = 0, length_tmp = 0;
	char **av, *delim = " \n\r\t", *temp;

	length_param = getnbwords(str, " ");
	av = malloc(sizeof(char *) * (length_param + 1));
	if (av == NULL || str == NULL)
		return (NULL);
	temp = strtok(str, delim);
	while (temp)
	{
		length_tmp = strlen(temp);
		av[i] = malloc(sizeof(char) * length_tmp);
		av[i] = temp;
		temp = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	if (temp != NULL)
		free(temp);
	return (av);
}
/**
 * parsePATH - parsing the PATH variable
 * and match with the command
 * @cmd: command enter
 * Return: the path of the command or NULL
 */
char *parsePATH(char *cmd)
{
	char *str, *ret, *s;
	struct stat sb;
	int i = 0;

	if (cmd[0] == '/')
		return (cmd);
	str = _getenv("PATH");
	s = strtok(str, ":");
	while (s)
	{
		ret = _concat(s, cmd);
		i = stat(ret, &sb);
		if (i == 0)
			return (ret);
		s = strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
