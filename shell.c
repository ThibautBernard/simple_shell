#include "holberton.h"
/**
 * main - main function
 * display prompt, create process, get command
 * @ac: number of arg
 * @av: arguments list
 * @env: environment
 * Return: (0)
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *buffer = NULL, **argv;
	size_t length = 0;
	int ret_gline = 0;

	_prompt();
	while (1 && (ret_gline = getline(&buffer, &length, stdin) != EOF))
	{
		argv = parseintab(buffer);
		child_process(argv, env);
		_prompt();
	}
	return (0);
}