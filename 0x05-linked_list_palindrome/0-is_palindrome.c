#include "lists.h"

/**
 * size_linkedlist - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: number of nodes
 */

int size_linkedlist(listint_t **head)
{
	listint_t *copy;
	int size = 0;

	copy = *head;

	while (copy)
	{
		copy = copy->next;
		size++;
	}
	return (size);

}

/**
 * copy_linkedlist - Check if linked_list is palindrome
 * @head: pointer to head of list
 * @array: pointer to copy linked list
 * Return: number of nodes
 */
void copy_linkedlist(listint_t **head, int *array)
{
	int i;
	listint_t *copy;

	copy = *head;
	i = 0;
	while (copy)
	{
		array[i] = copy->n;
		copy = copy->next;
		i++;
	}
}

/**
 * is_palindrome - Check if linked_list is palindrome
 * @head: pointer to head of list
 * Return: number of nodes
 */
int is_palindrome(listint_t **head)
{
	int size;
	int *array;
	int i;

	(void)array;
	size = size_linkedlist(head);
	array = malloc(size * sizeof(int));
	copy_linkedlist(head, array);
	size--;
	i = 0;
	while (size)
	{
		if (array[i] != array[size])
			return (0);
		i++;
		size--;
	}
	return (1);
}
