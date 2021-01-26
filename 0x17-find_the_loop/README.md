![](Top.png)

# Requirements

## General

> - Allowed editors: vi, vim, emacs
> - All your files will be interpreted/compiled on Ubuntu 14.04 LTS
> - Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
> - All your files should end with a new line
> - A README.md file, at the root of the folder of the project, is mandatory
> - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
> - You are not allowed to use global variables
> - No more than 5 functions per file
> - No standard library functions allowed. Any use of functions like printf, puts, calloc, realloc etc… is forbidden
> - In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
> - The prototypes of all your functions should be included in your header file called lists.h
> - Don’t forget to push your header file
> - All your header files should be include guarded
> - Please use this lists.h:

```sh
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

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif
```



## Whiteboarding

![](whiteboard1.jpg)

## Task

**0. Find the loop**

File: [0-find_loop.c](0-find_loop.c/) - [0-main.c](0-main.c/)

Write a function that finds the loop in a linked list.

- Prototype: listint_t *find_listint_loop(listint_t *head);
- Returns: The address of the node where the loop starts, or NULL if there is no loop
- You are not allowed to use malloc, free or arrays
- You can only declare a maximum of two variables in your function

Note: In order to compile the main file, you are provided with this static library. This library won’t be used during the correction; Its only purpose is for testing.

### 0-main.c

```sh
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *head2;
    listint_t *node;

    head2 = NULL;
    add_nodeint(&head2, 0);
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 3);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 98);
    add_nodeint(&head2, 402);
    add_nodeint(&head2, 1024);
    print_listint_safe(head2);
    node = find_listint_loop(head2);
    if (node != NULL)
    {
        printf("Loop starts at [%p] %d\n", (void *)node, node->n);
    }
    free_listint_safe(&head2);
    head = NULL;
    node = add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 5);
    add_nodeint(&head, 6);
    node->next = add_nodeint(&head, 7);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint_safe(head);
    node = find_listint_loop(head);
    if (node != NULL)
    {
        printf("Loop starts at [%p] %d\n", (void *)node, node->n);
    }
    free_listint_safe(&head);
    return (0);
}

```

### lib.c

```sh
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

```

### Test

```sh
alexa@ubuntu:~/0x17-find_the_loop$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
alexa@ubuntu:~/0x17-find_the_loop$ ./main
[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
alexa@ubuntu:~/0x17-find_the_loop$ 
```


If you want to use source file instead of the libloop.a library, please use this file lib.c

And compile it with this command: $ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main