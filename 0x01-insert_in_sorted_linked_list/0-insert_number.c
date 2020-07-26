#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: start of pointer
 * @number: new node
 * Return: address of the new element or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *currentNode;

	/* defining the start of the list */
	currentNode = *head;
	/* Allocate Memory to get a new Node*/
	newNode = malloc(sizeof(listint_t));

	/**
	 * Validate if newNode isn't Null
	 *Then: assigne in first node the new node and next node is Null
	 *Then validate if next posisition is null and value of new node is >
	 *assigne a new value for the next node
	 *if not go through position to find a value greater to be the newcurre
	 *at last return de value of node or null if not
	 *
	 **/
	if (newNode)
	{
		newNode->n = number;
		newNode->next = NULL;
		if (*head == NULL || (*head)->n >= newNode->n)
		{
			newNode->next = *head;
			*head = newNode;
		}
		else
		{
			while (currentNode->next && currentNode->next->n < newNode->n)
			{
				currentNode = currentNode->next;
			}
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
		return (newNode);
	}
	return (NULL);
}
