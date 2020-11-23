#include "holberton.h"

/**
 * add_nodechar_end - create a new node at the end
 * @head: pointer of pointer that store the head
 * of linked list of environments
 * @s: string to store in the new node
 * Return: null or new node
 */
envNodes *add_nodechar_end(envNodes **head, char *s)
{
	envNodes *next;

	next = malloc(sizeof(envNodes));
	if (next == NULL)
		return (NULL);
	if (next != NULL)
	{
		next->str = s; /** malloc ? **/
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
/**
 * transformEnv - array of array
 * into linked list
 * Return: linked list
 */
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
