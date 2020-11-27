#include "holberton.h"

/**
 * handle_ctrl - handle ctrl
 * @sig_num: int
 * Return: Nothing
 */
void handle_ctrl(int sig_num)
{
	(void)sig_num;
	_putstr("\n");
	_putstr("$ ");
}

/**
 * _promptatty - promptatty
 * @envt: environnement
 * Return: Nothing
 **/

void _promptatty(envNodes *envt)
{
	if (isatty(STDIN_FILENO) == 1)
		_prompt(envt);
}

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
	char *buffer = NULL;
	char **argv;
	size_t length = 0;
	envNodes *envt;
	int ret_gline = 0;
	bui b1[] = {
		{"env", print_env},
		{"exit", exit_process},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"help", _help},
		{"cd", _cd},
		{NULL, NULL}
	};

	(void)ac, (void)av, (void)env;
	signal(SIGINT, handle_ctrl);
	envt = transformEnv();
	_promptatty(envt);
	while ((ret_gline = getline(&buffer, &length, stdin)) != EOF)
	{
		argv = parseintab(buffer);
		if (buffer != NULL)
			free(buffer);
		if (_checkbuiltin(b1, argv) == 1)
		{
			_launchbuiltin(b1, argv, envt);
			freetab(argv);
		}
		else
		{
			_child_process(argv, env, envt);
			freetab(argv);
		}
		_promptatty(envt);
		buffer = NULL;
	}
	free(buffer);
	free_list(envt);
	return (0);
}
