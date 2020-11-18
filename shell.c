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
	bui b1[] = {
		{"exit", exit_process},
		{"env", print_env},
		{NULL, NULL}
	};

	_prompt();
	while (1 && (ret_gline = getline(&buffer, &length, stdin) != EOF))
	{
		argv = parseintab(buffer);
		if (_checkbuiltin(b1, argv[0]) == 1)
		{
			_launchbuiltin(b1, argv[0]);
		}
		else
		{
			child_process(argv, env);
		}
		_prompt();
	}
	return (0);
}
