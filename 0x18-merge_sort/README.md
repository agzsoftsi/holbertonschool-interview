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
> - Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
> - In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
> - The prototypes of all your functions should be included in your header file called sort.h
> - Don’t forget to push your header file
> - All your header files should be include guarded
> - A list/array does not need to be sorted if its size is less than 2

## More info

For this project you are given the following print_array function:

```sh
alexa@ubuntu-xenial:0x18-merge_sort$ cat print_array.c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

- Our file print_array.c (containing the print_array function) will be compiled with your functions during the correction.
- Please declare the prototype of the function print_array in your sort.h header file
- Please, note this format is used for Big O notation:

> - O(1)
> - O(n)
> - O(n!)
> - n square -> O(n^2)
> - log(n) -> O(log(n))
> - n * log(n) -> O(nlog(n))


## Whiteboarding

![](whiteboard1.jpg)

## Task

**0. Merge sort**

File: [0-merge_sor](0-merge_sor/) - [0-main.c](0-main.c/) - [0-O](0-O/)

Write a function that sorts an array of integers in ascending order using the Merge Sort algorithm:

- Prototype: void merge_sort(int *array, size_t size);
- You must implement the top-down merge sort algorithm
> - When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}
> - Sort the left array before the right array
- You are allowed to use printf
- You are allowed to use malloc and free only once (only one call)
- Output: see example

In the file 0-O, write the Big O notations of the time complexity of the Merge Sort algorithm, with 1 notation per line:

- in the best case
- in the average case
- in the worst case

### 0-main.c

```sh
alexa@ubuntu-xenial:0x18-merge_sort$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

```

### testing

```sh
alexa@ubuntu-xenial:0x18-merge_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
alexa@ubuntu-xenial:0x18-merge_sort$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:0x18-merge_sort$

```