#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: ptr head of list
 * Return: 0 if no cycle, 1 if cycle
 */
int check_cycle(listint_t *list)
{

	listint_t *hare, *turtle = list;

	if (!list)
		return (0);

	hare = list->next;

	while (hare)
	{
		if (hare->next)
			hare = hare->next->next;
		else
			hare = hare->next;

		turtle = turtle->next;
		if (hare == turtle)
			return (1);
	}
	return (0);
}
