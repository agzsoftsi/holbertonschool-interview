![](Top.png)

# Requirements

## General

> - Allowed editors: vi, vim, emacs
> - All your files will be compiled on Ubuntu 14.04 LTS
> - Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
> - All your files should end with a new line
> - A README.md file, at the root of the folder of the project, is mandatory
> - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
> - You are not allowed to use global variables
> - No more than 5 functions per file
> - You are only allowed to use the printf function of the standard library. Any call to another function like strdup, malloc, … is forbidden.
> - In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
> - The prototypes of all your functions should be included in your header file called search_algos.h
> - Don’t forget to push your header file
> - All your header files should be include guarded



## Whiteboarding

![](whiteboard1.jpg)


## Task

**0. Advanced Binary Search**

File: [0-advanced_binary.c](0-advanced_binary.c/) - [0-main.c](0-main.c/)

You may have noticed that basic binary search does not necessarily return the index of the first value in the array (if this value appears more than once in the array). In this exercise, you’ll have to solve this problem.

Write a function that searches for a value in a sorted array of integers.

- Prototype : int advanced_binary(int *array, size_t size, int value);
- array is a pointer to the first element of the array to search in
- size is the number of elements in array
- value is the value to search for
- Your function must return the index where value is located
- You can assume that array will be sorted in ascending order
- If value is not present in array or if array is NULL, your function must return -1
- Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)
- You have to use recursion. You may only use one loop (while, for, do while, etc.) in order to print the array

```sh
wilfried@0x1D-search_algorithms$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1D-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary

```


Testing

```sh
wilfried@0x1D-search_algorithms$ ./0-advanced_binary
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```