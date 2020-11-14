#include "holberton.h"

/**
 * child_process - create child process
 * @argv: argumùment to execve
 * Return: (0)
 */
int child_process(char **argv, char **env)
{
	int child, status;

	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror("Error exec");;
	}
	else
		wait(&status);
	return (0);
}
int child_process_built(char **argv)
{
	int child, status;
	(void)argv;
	child = fork();
	if (child == -1)
		perror("Error chill process");
	if (child == 0)
	{
		//call builtin
	}
	else
		wait(&status);
	return (0);
}

