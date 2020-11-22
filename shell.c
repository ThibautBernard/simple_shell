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
	(void)env;
	char *buffer = NULL, **argv;
	size_t length = 0;
	envNodes *envt;
	int ret_gline = 0, i = 0;
	bui b1[] = {
		{"env", print_env},
		{"exit", exit_process},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};
	envt = transformEnv();
	_prompt(envt);
	while (1 && (ret_gline = getline(&buffer, &length, stdin)) != EOF)
	{
		argv = parseintab(buffer);
//		i = check_sep(argv);
//		printf("%d\n", i);
		if (_checkbuiltin(b1, argv) == 1)
		{
			_launchbuiltin(b1, argv, envt);
		}
		else
		{
			_child_process(argv, env, envt);
		}
//		if (isatty(STDIN_FILENO)
			_prompt(envt);
	}
	//free(buffer);
	//free(argv);*/
	return (0);
}
