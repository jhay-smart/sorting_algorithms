#include "sort.h"

/**
* shell_sort - This is the function that sorts an array of integers using
* the shell sort algorithm with Knuth sequence
* @array: This represents the array of integers
* @size: This is the size of the array
*
* Return: none
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, k, i;
	int tmp;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size)
		;

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (k = i; k >= gap && tmp <= array[k - gap]; k -= gap)
				array[k] = array[k - gap];
			array[k] = tmp;
		}
		print_array(array, size);
	}
}
