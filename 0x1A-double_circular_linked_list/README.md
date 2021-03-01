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
> - The only C standard library functions allowed are malloc, free, and strdup. Any use of functions like printf, puts, calloc, realloc etc… is forbidden
> - In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
> - The prototypes of all your functions should be included in your header file called list.h
> - Don’t forget to push your header file
> - All your header files should be include guarded


## More info

Please use this data structure for this project:

```sh
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
  char *str;
  struct List *prev;
  struct List *next;
} List;
```

## Whiteboarding

![](whiteboard1.jpg)

## Task

**0. Add Nodes**

File: [0-add_node.c](0-add_node.c/) - [0-main.c](0-main.c/)

Create the source file 0-add_node.c that contains the following functions:

- Add a new node to the end of a double circular linked list:
> - Prototype: List *add_node_end(List **list, char *str);
> - List: the list to modify
> > - str: the string to copy into the new node
> > - Returns: Address of the new node, or NULL on failure
- Add a new node to the beginning of a double circular linked list:
> - Prototype: List *add_node_begin(List **list, char *str);
> - List: the list to modify
> > - str: the string to copy into the new node
> > - Returns: Address of the new node, or NULL on failure

### 0-main.c

```sh
alexa@ubuntu:0x1A-double_circular_linked_list$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
    List *tmp;

    tmp = list;
    while (tmp)
    {
        printf("%s\n", tmp->str);
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
        if (tmp == list)
            break;
    }
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    List *list;

    list = NULL;
    add_node_end(&list, "Holberton");
    add_node_end(&list, "School");
    add_node_end(&list, "Full");
    add_node_end(&list, "Stack");
    add_node_end(&list, "Engineer");

    printf("Added to the end:\n");
    print_list(list);
    list = NULL;
    add_node_begin(&list, "Holberton");
    add_node_begin(&list, "School");
    add_node_begin(&list, "Full");
    add_node_begin(&list, "Stack");
    add_node_begin(&list, "Engineer");

    printf("Added to the beginning:\n");
    print_list(list);
    return (0);
}

```

### testing

```sh
alexa@ubuntu:0x1A-double_circular_linked_list$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
alexa@ubuntu:0x1A-double_circular_linked_list$ ./a.out 
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
alexa@ubuntu:0x1A-double_circular_linked_list$ 

```