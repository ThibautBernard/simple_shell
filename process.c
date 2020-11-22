#include "holberton.h"



/**
 * _child_process - create child process
 * @argv: argumùment to execve
 * @env: environnement
 * @environ: environ
 * Return: (0)
 */
char *_child_process(char **argv, char **env, envNodes *environ)
{
	char *s, *s1, *path;
	int j;
	int child, status;
	(void)env;
	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
		path = checkPath(argv[0], &environ);/*checkPath*/
		if (path != NULL)
		{
			if (execve(path, argv, NULL) == -1)
			{
				perror("Error exec");
				_exit(status);
			}
		}
		else
		{
			s = _getenv("PWD", &environ);
			s1 = _concat(s, argv[0], '/');
			free(s);
			free(argv[0]);
			argv[0] = _strdup(s1);
			if (execve(s1, argv, NULL) == -1)
			{
				perror("Error exec");
				_exit(status);
				free(s1);
			}
			free(s1);
		}
	}
	else
		wait(&status);
/*	free(path);*/
	return (path);
}
/**
 * child_process_built - create child process
 * for builtin
 * @argv: arguments
 * Return: 0
 */
int child_process_built(char **argv)
{
	int child, status;
	(void)argv;
	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
	}
	else
		wait(&status);
	return (0);
}

