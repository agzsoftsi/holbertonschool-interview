#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int first, int last);
int recursive_search(int *array, size_t first, size_t last, int value);
int linear_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);

#endif
