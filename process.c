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
	int child, status;
	struct stat *sb;
	(void)env;

	sb = malloc(sizeof(struct stat));
	if (sb == NULL)
		return (NULL);
	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
		path = checkPath(argv[0], &environ);/*checkPath*/
		if (path != NULL)
			exec(path, argv, status);
		else if (stat(argv[0], sb) == 0)
			exec(argv[0], argv, status);
		else if (path == NULL)
		{
			s = _getenv("PWD", &environ);
			s1 = _concat(s, argv[0], '/');
//			free(s);
			free(argv[0]);
			argv[0] = _strdup(s1);
			exec(s1, argv, status);
	//		free(s1);
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

