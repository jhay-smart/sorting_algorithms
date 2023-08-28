#include "sort.h"
/**
 *selection_sort- function that sorts using selection sort algorithm
 *
 *@array:This is the array to be sorted
 *@size:The is the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, t;
	int temp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1, t = i + 1; j > i; j--)
		{
			if (array[j] < array[t])
			{
				t = j;
			}
		}
		if (array[i] > array[t])
		{
			temp = array[i];
			array[i] = array[t];
			array[t] = temp;
			print_array(array, size);
		}
	}
}
