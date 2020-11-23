#include "holberton.h"

/**
 * freetab - free a char **;
 * @tb: table to free
 * Return: 0;
 */
int freetab(char **tb)
{
	int j;

	if (tb == NULL)
	{
		_putstr("[freetab] can't free : tab is NULL b is free\n");
		return (-1);
	}
	for (j = 0; tb[j]; j++)
	{
		if (tb[j] == NULL)
		{
			_putstr("[freetab] can't free: line is NULL\n");
			return (-1);
		}
		free(tb[j]);
	}
	free(tb);
	return (0);
}

void free_list(envNodes *head)
{
		envNodes *tmp;

		while (head != NULL)
		{
			tmp = head;
			head = head->next;
			free(tmp->str);
			free(tmp);
		}
}
