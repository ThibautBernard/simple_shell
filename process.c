#include "holberton.h"
/**
 * _child_process - create child process
 * @argv: argumùment to execve
 * @env: legacy environnement
 * @envi: linked list environ
 * Return: (0)
 */
char *_child_process(char **argv, char **env, envNodes *envi)
{
	char *s, *s1, *path;
	int child, status, b;
	struct stat *sb;
	(void)env;

	if (argv[0] == NULL)
		return (NULL);
	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
		sb = malloc(sizeof(struct stat));
		if (sb == NULL)
			return (NULL);
		b = stat(argv[0], sb);
		free(sb);
		path = checkPath(argv[0], &envi);
		if (path != NULL)
			exec(path, argv, status);
		else if (b  == 1)
		{
			s = _getenv("PWD", &envi);
			s1 = _concat(s, argv[0], '/');
			free(argv[0]);
			free(s);
			argv[0] = _strdup(s1);
			free(s1);
			exec(argv[0], argv, status);
		}
		else if (b == 0)
			exec(argv[0], argv, status);
		else
			return (NULL);
	}
	else
		wait(&status);
	return (path);
}
