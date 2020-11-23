#include "holberton.h"

void exec(char *cmd, char **argv, int status)
{
	if (execve(cmd, argv, NULL) == -1)
	{
				perror("Error exec");
				_exit(status);
	}
}
