#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, t;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (t = 0; t < size - 1; t++)
		{
			if (array[t] > array[t + 1])
			{
				temp = array[t];
				array[t] = array[t + 1];
				array[t + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
