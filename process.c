#include "holberton.h"

/**
 * child_process - create child process
 * @argv: argumùment to execve
 * @env: environnement
 * Return: (0)
 */
char *_child_process(char **argv, char **env)
{
	char *path;
	int child, status;

	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
		path = parsePATH(argv[0]);
		if (execve(path, argv, env) == -1)
			perror("Error exec");
	}
	else
		wait(&status);
//	free(path);
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

