#include "sort.h"

/**
 * counting_sort - This sorts an array with the Counting sort algorithm
 * @array: This is the array to sort
 * @size: This represents size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max, num, a, l;
	size_t i, j, m, n;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_arr = malloc(sizeof(size_t) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	for (a = 0; a <= max; a++)
		count_arr[a] = 0;
	for (j = 0; j < size; j++)
	{
		num = array[j];
		count_arr[num] += 1;
	}
	for (l = 1; l <= max; l++)
		count_arr[l] += count_arr[l - 1];
	print_array(count_arr, max + 1);
	for (m = 0; m < size; m++)
	{
		out_arr[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(count_arr);
	free(out_arr);
}
