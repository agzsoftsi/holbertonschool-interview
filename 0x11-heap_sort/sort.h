#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void swap(int *a, int *b, int *array, size_t n);
void heap_root(int *arr, int n, int i, size_t size);
void heap_sort(int *array, size_t size);
#endif /* _SORT_H_ */
