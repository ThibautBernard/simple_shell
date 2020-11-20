#include "holberton.h"

envNodes *add_nodechar_end(envNodes **head, char *s)
{
	envNodes *next;

	next = malloc(sizeof(envNodes));
	if (next == NULL)
		return (NULL);
	if (next != NULL)
	{
		next->str = s; // malloc ? 
		next->next = NULL;
		if (*head == NULL)
			*head = next;
		else
		{
			envNodes *tmp = *head;

			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = next;
		}
	}
	return (next);
}
envNodes *transformEnv(void)
{
	int i = 0;

	envNodes *head = NULL;
	while (environ[i])
	{
		add_nodechar_end(&head, environ[i]);
		i++;
	}
	return (head);
}
