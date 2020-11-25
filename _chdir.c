#include "holberton.h"

/**
 * changedir - update the PWD environement variable and OLDPWD with new one
 * @dest: destination
 * @env: environement
 * Return: 1 on success and 0 and fail
 */

int changedir(char *dest, envNodes **env)
{
	char *tmp;

	if (chdir(dest) == -1)
	{
/*		printf("-bash: cd: %s: No such file or directory\n", dest);*/
		return (-1);
	}
	else
	{
		tmp = _getenv("PWD", env);
		if (tmp != NULL)
		{
			_setenv_chdir("OLDPWD", tmp, env);
			_setenv_chdir("PWD", dest, env);
			free(tmp);
		}
		return (0);
	}
}
/**
 * _cd - Change directory
 * @a: integer
 * @tb: doble char table
 * @env: environement
 * Return: 1 on success and 0 and fail
 */

int _cd(int a, char **tb, envNodes **env)
{
	char *tmp;
	char *tmp2;
	(void)a;

	if (tb[1] == NULL)
	{
		tmp = _getenv("HOME", env);
		changedir(tmp, env);
		free(tmp);
	}
	else if (_strncmp(tb[1], "-", 1) == 0)
	{
		tmp = _getenv("OLDPWD", env);
		changedir(tmp, env);
		free(tmp);
	}
	else if (_strncmp(tb[1], "/", 1) == 0)
	{
		changedir(tb[1], env);
	}
	else
	{
		tmp = _getenv("PWD", env);
		tmp2 = _mconcat(tmp, "/");
		free(tmp);
		tmp = _mconcat(tmp2, tb[1]);
		changedir(tmp, env);
		free(tmp);
	}
	return (0);
}
