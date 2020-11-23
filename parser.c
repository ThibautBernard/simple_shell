#include "holberton.h"
/**
 * parseintab - parse a string
 * in function of delim into a char **
 * @str: string to parse
 * Return: NULL or the pointer of pointer
 */
char **parseintab(char *str)
{
	int i = 0, j = 0, length_param = 0, length_tmp = 0;
	char **av, *delim = " \n\r\t\f", *temp;

	length_param = getnbwords(str, " ");
	av = malloc(sizeof(char *) * (length_param + 1));
	if (av == NULL || str == NULL)
		return (NULL);
	temp = _strtok(str, delim);
	while (temp)
	{
		if (_strncmp(temp, "#", 1) == 0)
			return (av);
		length_tmp = strlen(temp);
		av[i] = malloc(sizeof(char) * length_tmp + 1);
		if (av[i] == NULL)
			return (NULL);
		for (j = 0; temp[j]; j++)
		{
			av[i][j] = temp[j];
		}
		av[i][j] = '\0';
		temp = _strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	return (av);
}
/**
 * checkPATH - check in the path folder and return correct path if found
 * and match with the command
 * @cmd: command enter
 * @env: environment
 * Return: the path of the command
 * or NULL if path not found or if cmd not found in path
 */
char *checkPath(char *cmd, envNodes **env)
{
	char *str, *ret, *s;
	struct stat *sb;
	int i = 0;

	sb = malloc(sizeof(struct stat));
	if (sb == NULL)
		return (NULL);
	str = _getenv("PATH=/", env);
	if (str == NULL)
		return (NULL);
	s = _strtok(str, ":");
	while (s)
	{
		ret = _concat(s, cmd, '/');
		i = stat(ret, sb);
		if (i == 0)
		{
			free(sb);
			free(str);
			return (ret);
		}
		s = _strtok(NULL, ":");
		free(ret);
		i++;
	}
	free(str);
	free(sb);
	return (NULL);
}
