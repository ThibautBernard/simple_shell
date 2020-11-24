#include "holberton.h"
/**
 * _setenv_chdir - set a variable or modify it in env
 * @var: variable name
 * @value: value to change
 * @env: double pointer that store adress of the
 * linked list environemment
 * Return: 1 if succeed
 */
int _setenv_chdir(char *var, char *value, envNodes **env)
{
	int i = 0, length_var = 0;
	char  *tmpStr;
	envNodes *current = *env;

	if (var == NULL || value == NULL)
	{
		write(STDERR_FILENO, "Failure\n", 9);
		return (0);
	}
	length_var = _strlen(var);
	tmpStr = _concat(var, value, '='); /** free tmpStr **/
	while (current->next)
	{
		if (_strncmp(current->str, var, length_var) == 0)
		{
			/**free tmp->str**/
			current->str = tmpStr; /** strdup ? **/
			/**free(tmpStr);**/
			return (1);
		}
		 current = current->next;
	}
	if (_strncmp(current->str, var, length_var) == 0)
		current->str = tmpStr;
	else
		add_nodechar_end(&current, tmpStr);
	/**free(tmpStr); **/
	return (1);
}
