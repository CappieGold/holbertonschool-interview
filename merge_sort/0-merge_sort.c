#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges two sorted sub-arrays into one sorted sub-array
 * @array: the original array
 * @tmp: temporary buffer for merging
 * @left: start index of the left sub-array
 * @mid: end index (exclusive) of left / start index of right
 * @right: end index (exclusive) of the right sub-array
 */
static void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left; i < right; i++)
		tmp[i] = array[i];

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (tmp[i] <= tmp[j])
			array[k++] = tmp[i++];
		else
			array[k++] = tmp[j++];
	}

	while (i < mid)
		array[k++] = tmp[i++];

	while (j < right)
		array[k++] = tmp[j++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_rec - recursively splits and merges the array
 * @array: the array to sort
 * @tmp: temporary buffer
 * @left: start index
 * @right: end index (exclusive)
 */
static void merge_sort_rec(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_sort_rec(array, tmp, left, mid);
	merge_sort_rec(array, tmp, mid, right);
	merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *              using the top-down Merge Sort algorithm
 * @array: the array to sort
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_rec(array, tmp, 0, size);

	free(tmp);
}
