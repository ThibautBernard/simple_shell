#include "holberton.h"
/**
 * _prompt - display a prompt
 * @env: linked list of environnement
 * Return: nothing
 */
void _prompt(envNodes *env)
{
	char *prompt;

	prompt = _getenv("PS1", &env);
	if (prompt == NULL)
		_putstr("$ ");
	else
		_putstr(prompt);
}
