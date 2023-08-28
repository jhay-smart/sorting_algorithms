#include "sort.h"

/**
 * swap - This swaps 2 int values
 * @array: This is the integer array to be sorted
 * @size: This is the size of the array
 * @a: This is the address of first value
 * @j: This is the address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *j)
{
	if (*a != *j)
	{
		*a = *a + *j;
		*j = *a - *j;
		*a = *a - *j;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @lw: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lw, ssize_t hi)
{
	int i, k, pivot = array[hi];

	for (i = k = lw; k < hi; k++)
		if (array[k] < pivot)
			swap(array, size, &array[k], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}

/**
 * quicksort -This quicksorts via Lomuto partitioning scheme
 * @array:This is  the integer array to sort
 * @size: This is the size of the array
 * @lw:This is the low index of the sort range
 * @hi: This the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lw, ssize_t hi)
{
	if (lw < hi)
	{
		size_t p = lomuto_partition(array, size, lw, hi);

		quicksort(array, size, lw, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - calls quicksort
 * @array: This is the integer array to sort
 * @size: This is the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
