![](Top.png)

# Requirements

## General

> - Allowed editors: vi, vim, emacs
> - All your files will be compiled on Ubuntu 14.04 LTS
> - Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
> - All your files should end with a new line
> - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
> - You are not allowed to use global variables
> - No more than 5 functions per file
> - In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
> - The prototypes of all your functions should be included in your header file called palindrome.h
> - Don’t forget to push your header file
> - All your header files should be include guarded


## Whiteboarding

![](whiteboard1.jpg)

## Task

**0. Palindrome unsigned integer**

File: [0-is_palindrome.c](0-is_palindrome.c/) - [palindrome.h](palindrome.h/)

Technical interview preparation:

Write a function that checks whether or not a given unsigned integer is a palindrome.

- Prototype: int is_palindrome(unsigned long n);
- Where n is the number to be checked
- Your function must return 1 if n is a palindrome, and 0 otherwise
- You are not allowed to allocate memory dynamically (malloc, calloc, …)

- 0-main.c

```sh
alex@~/0x08-palindrome_integer$ cat 0-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    unsigned long n;
    int ret;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is ", n);
    if (ret == 0)
        printf("not ");
    printf("a palindrome.\n");

    return (EXIT_SUCCESS);
}
alex@~/0x08-palindrome_integer$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
alex@~/0x08-palindrome_integer$ ./palindrome 1
1 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 11
11 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 112
112 is not a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 121
121 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
alex@~/0x08-palindrome_integer$
```