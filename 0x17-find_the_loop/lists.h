#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *find_listint_loop(listint_t *head);

#endif
