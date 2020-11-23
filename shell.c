#include "holberton.h"
/**
 * main - main function
 * display prompt, get command, transfer command
 * to function
 * @ac: number of arg
 * @av: arguments list
 * @env: environment
 * Return: (0)
 */
int main(int ac, char **av, char **env)
{
	(void)ac, (void)av, (void)env;
	char *buffer = NULL, **argv;
	size_t length = 0;
	envNodes *envt;
	int ret_gline = 0;
	bui b1[] = {
		{"env", print_env},
		{"exit", exit_process},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};
	envt = transformEnv();
	if (isatty(STDIN_FILENO) == 1)
		_prompt(envt);
	while ((ret_gline = getline(&buffer, &length, stdin)) != EOF)
	{
		argv = parseintab(buffer);
		if (_checkbuiltin(b1, argv) == 1)
			_launchbuiltin(b1, argv, envt);
		else
			_child_process(argv, env, envt);
	if (isatty(STDIN_FILENO) == 1)
		_prompt(envt);
	}
	return (0);
}
