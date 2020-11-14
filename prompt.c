#include "holberton.h"
/**
 * _prompt - display a prompt
 * Return: nothing
 */
void _prompt(void)
{
	char *prompt;

	prompt = _getenv("PS1");
	if (prompt == NULL)
		_putstr("($) ");
	else
		_putstr(prompt);
}
