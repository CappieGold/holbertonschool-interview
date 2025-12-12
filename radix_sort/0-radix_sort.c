#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in the array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Counting sort for a specific digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Exponent (1, 10, 100, ...)
 * Return: 1 on success, 0 on failure
 */
int counting_sort_radix(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return (0);

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	return (1);
}

/**
 * radix_sort - Sorts an array using LSD Radix Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		if (!counting_sort_radix(array, size, exp))
			return;
		print_array(array, size);
	}
}
