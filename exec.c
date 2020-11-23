#include "holberton.h"

/**
 * exec - Execute a command or return an error
 * @cmd: command
 * @argv: tab with copie of  arguments
 * @status: exit status
 * Return: void
 */

void exec(char *cmd, char **argv, int status)
{
	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Error exec");
		_exit(status);
	}
}
