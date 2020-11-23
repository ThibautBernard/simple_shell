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
/*
 * _setenv - set a variable or modify it in env
 * that is a linked list
 * @n: integer (not used)
 * @s: array of array of commands && parameters
 * given by the user
 * @env: double pointer that store adress of the
 * linked list environemment
 * Return: 1 if succeed
 */
int _setenv(int n, char **s, envNodes **env)
{
	int i = 0, length_var = 0;
	char *var, *value, *tmpStr;
	(void)n;

	envNodes *current = *env;
	while (s[i])
		i++;
	if (i != 3 || *env == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 9);
		return (0);
	}
	var = s[1]; // malloc ?
	value = s[2]; // malloc ?
	length_var = _strlen(var);
	tmpStr = _concat(var, value, '='); // free tmpStr
	while (current->next)
	{
		if (strncmp(current->str, var, length_var) == 0)
		{
			//free tmp->str
			current->str = tmpStr; // ? strdup
//			free(tmpStr);
			return (1);
		}
		 current = current->next;
	}
	if (strncmp(current->str, var, length_var) == 0)
		current->str = tmpStr;
	else
		add_nodechar_end(&current, tmpStr);
	//free(tmpStr);
	return (1);
}
/**
 * _unsetenv - delete a variable in env
 * @n: integer (not used)
 * @s: array of array of commands && parameters
 * given by the user
 * Return: 1 if succeed
 */
int _unsetenv(int n, char **s, envNodes **env)
{
	int i = 0, length_var = 0, count = 0;
	char *var;
	(void)n;

	envNodes *current = *env, *previous;
	while (s[i])
		i++;
	if (i != 2 ||*env == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 9);
		return (0);
	}
	var = s[1]; // malloc ?
	length_var = _strlen(var);
	while (current)
	{
		if (_strncmp(current->str, var, length_var) == 0)
		{
			if (count != 0)
				previous->next = current->next;
			else
				*env = current->next;
			free(current);
			return (1);
		}
		count++;
		previous = current;
		current = current->next;
	}	
	return (1);
}
/**
 * _getenv - get value of env variable
 * @name: name of the variable
 * @env: environment in linked list
 * Return: string to the value or NULL
 */
char *_getenv(const char *name, envNodes **env)
{
	int i = 0, x = 0, l, length_name = 0, length_env = 0;
	char *tmp, *s;

	envNodes *tmp_env = *env;
	if (name == NULL)
		return (NULL);
	length_name = _strlen_const(name);
	while (tmp_env)
	{
		if (_strncmp(name, tmp_env->str, length_name) == 0)
		{
			length_env = _strlen(tmp_env->str);
			tmp = malloc(sizeof(char) * (length_env - length_name));
			if (tmp == NULL)
			{
				//perror("Error getenv");
				return (NULL);
			}
			l = (length_name);
			s = tmp_env->str;
			tmp[x] = '/';
			x++;
			while (s[l])
			{
				tmp[x] = s[l];
				l++;
				x++;
			}
			tmp[x] = '\0';
			return (tmp);
		}
		tmp_env = tmp_env->next;
		i++;
	}
	return (NULL);
}
/**
 * print_env - print the environnement
 * @n: nothing
 * @s: double array of arguments commands
 * @env: pointer of pointer that store adress
 * of the linked list
 * Return: nothing
 */
int print_env(int n, char **s, envNodes **env)
{
	int i = 0;
	envNodes *tmp = *env;
	(void)s;
	while (tmp)
	{
		_putstr(tmp->str);
		_putstr("\n");
		tmp = tmp->next;
		i++;
	}
	return (n);
}
