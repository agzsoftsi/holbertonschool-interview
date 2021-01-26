#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * struct listdone_s - singly linked list
 * @node: node
 * @next: points to the next node
 *
 * Description: singly linked list node done structure
 * for Holberton project
 */
typedef struct listdone_s
{
	const struct listint_s *node;
	struct listdone_s *next;
} listdone_t;


/**
 * _find_in_list - Search for a node in a list
 *
 * @done: The list of known nodes
 * @node: The address of the node being searched
 *
 * Return: The address of the node if it was found. NULL otherwise
 */
const listint_t *_find_in_list(listdone_t **done, const listint_t *node)
{
	listdone_t *p;

	p = *done;
	while (p)
	{
		if (p->node == node)
		{
			return (p->node);
		}
		p = p->next;
	}
	p = malloc(sizeof(listdone_t));
	if (p == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	p->node = node;
	p->next = *done;
	*done = p;
	return (NULL);
}

/**
 * _free_done - Free a list
 *
 * @done: A pointer to the first element of a list
 */
void _free_done(listdone_t *done)
{
	listdone_t *tmp;

	while (done)
	{
		tmp = done->next;
		free(done);
		done = tmp;
	}
}

/**
 * add_nodeint - Add a node at the beginning of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * free_listint_safe - Free a list that can contain a loop
 *
 * @h: A pointer to the first element of a list
 *
 * Return: The number of element in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listdone_t *done;
	listint_t *head;
	listint_t *tmp;
	size_t n;

	head = *h;
	n = 0;
	done = NULL;
	while (head)
	{
		if (_find_in_list(&done, head) != NULL)
		{
			_free_done(done);
			*h = NULL;
			return (n);
		}
		tmp = head;
		head = head->next;
		free(tmp);
		n++;
	}
	_free_done(done);
	*h = NULL;
	return (n);
}

/**
 * print_listint_safe - Prints a list thaht can contains a loop
 *
 * @head: A pointer to the first element of a list
 *
 * Return: The number of element printed
 */
size_t print_listint_safe(const listint_t *head)
{
	listdone_t *done;
	size_t n;

	n = 0;
	done = NULL;
	while (head)
	{
		if (_find_in_list(&done, head) != NULL)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			_free_done(done);
			return (n);
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		n++;
	}
	_free_done(done);
	return (n);
}