#include "holberton.h"
/**
 * _strlen_const - _strlen
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
 * _setenv - set a variable or modify it in env
 * @n: integer (not used)
 * @s: array of array of commands && parameters
 * @env: double pointer that store adress of the
 * linked list environemment
 * Return: 1 if succeed
 */
int _setenv(int n, char **s, envNodes **env)
{
	int i = 0, length_var = 0;
	char *var, *value, *tmpStr;
	envNodes *current = *env;


	(void)n;
	while (s[i])
		i++;
	if (i != 3 || *env == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 9);
		return (0);
	}
	var = _strdup(s[1]); /** malloc ? **/
	value = _strdup(s[2]); /** malloc ? **/
	length_var = _strlen(var);
	tmpStr = _concat(var, value, '='); /** free tmpStr **/
	while (current->next)
	{
		if (_strncmp(current->str, var, length_var) == 0)
		{
			/**free tmp->str**/
			free(current->str);
			current->str = _strdup(tmpStr); /** strdup ? **/
			free(var);
			free(value);
			free(tmpStr);
			/**free(tmpStr);**/
			return (1);
		}
		 current = current->next;
	}
	if (_strncmp(current->str, var, length_var) == 0)
		current->str = _strdup(tmpStr);
	else
		add_nodechar_end(&current, tmpStr);
	free(tmpStr);
	free(var);
	free(value);
	return (1);
}
/**
 * _unsetenv - delete a variable in env
 * @n: integer (not used)
 * @s: array of array of commands && parameters
 * @env: linked list of the environnment
 * given by the user
 * Return: 1 if succeed
 */
int _unsetenv(int n, char **s, envNodes **env)
{
	int i = 0, length_var = 0, count = 0;
	char *var;
	envNodes *current = *env, *previous;

	(void)n;
	while (s[i])
		i++;
	if (i != 2 || *env == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 9);
		return (0);
	}
	var = _strdup(s[1]); /** malloc ? **/
	length_var = _strlen(var);
	while (current)
	{
		if (_strncmp(current->str, var, length_var) == 0)
		{
			if (count != 0)
				previous->next = current->next;
			else
				*env = current->next;
			free(current->str);
			free(current);
			free(var);
			return (1);
		}
		count++;
		previous = current;
		current = current->next;
	}
	free(var);
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
	if (name[0] == '\0')
		return (NULL);
	length_name = _strlen_const(name);
	while (tmp_env)
	{
		if (_strncmp(name, tmp_env->str, length_name) == 0)
		{
			length_env = _strlen(tmp_env->str);
			tmp = malloc(sizeof(char) * (length_env - length_name));
			if (tmp == NULL)
				return (NULL);
			l = (length_name + 1);
			s = tmp_env->str;
			/**tmp[x] = '/';**/
			/**x++;**/
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
