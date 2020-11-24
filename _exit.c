#include "holberton.h"

/**
 * exit_process - exit all process
 * @nb: status number
 * @s: array of array of command given
 * @env: linked list of environment
 * Return: nothing
 */
int exit_process(int nb, char **s, envNodes **env)
{
	int sts = 0;
	(void)nb;
	(void)s;
	(void)env;
	if (s[1])
	{
		sts = _atoi(s[1]);
		if (sts > 0 && sts < 2147483647)
		{
			freetab(s);
			exit(sts);
		}
		else
		{
			freetab(s);
			_putstr(": 1: exit: Illegal number: -1\n");
		}
		/** free_list(*env); **/
	}
	else
	{
		freetab(s);
		/** free_list(*env); **/
		exit(sts);
	}
	return (0);
}
