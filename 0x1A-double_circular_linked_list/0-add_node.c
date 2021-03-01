#include "list.h"

/**
 * create_node - Creates a node with the given data
 * @str: the string to copy into the new node
 * Return: pointer to the newly created node
 */
List *create_node(char *str)
{
	List *new = NULL;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: a pointer to the newly added node
 */
List *add_node_end(List **list, char *str)
{
	List *last, *new;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		(*list)->prev = new;
		new->prev = last;
		new->next = (*list);
	}
	return (new);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular
 * linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: a pointer to the newly added node
 */
List *add_node_begin(List **list, char *str)
{
	List *last, *new;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		(*list)->prev = new;
		new->prev = last;
		new->next = (*list);
		*list = new;
	}
	return (new);
}
