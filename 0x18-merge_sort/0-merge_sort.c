#include "sort.h"

/**
 * sort - Sort subarrays
 * @arr: Pointer to array of integers
 * @l: Pointer to left subarray
 * @r: Pointer to right subarray
 * @start: First index of left subarray
 * @mid: Last index of left subarray
 * @end: Last index of right subarray
 *
 * Return: None
 */
void sort(int *arr, int *l, int *r, int start, int mid, int end)
{
	int left_iter, right_iter, array_iter;
	int left_size = mid - start + 1;
	int right_size = end - mid;

	left_iter = right_iter = 0;
	array_iter = start;

	while (left_iter < left_size && right_iter < right_size)
	{
		if (l[left_iter] < r[right_iter])
		{
			arr[array_iter] = l[left_iter];
			left_iter++;
		}
		else
		{
			arr[array_iter] = r[right_iter];
			right_iter++;
		}
		array_iter++;
	}

	while (left_iter < left_size)
	{
		arr[array_iter] = l[left_iter];
		left_iter++;
		array_iter++;
	}

	while (right_iter < right_size)
	{
		arr[array_iter] = r[right_iter];
		right_iter++;
		array_iter++;
	}
}