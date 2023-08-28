#include "sort.h"
#include <stdio.h>

int partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);

/**
* quick_sort_hoare - sorts an array using the Quick sort algorithm
* @array: array of integers to be sorted
* @size: size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_recursive(array, 0, (int)size - 1);
}

/**
* partition - Hoare partition scheme
* @array: array to partition
* @low: starting index of the partition
* @high: ending index of the partition
* Return: index of the partition pivot
*/
int partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1, j = high + 1;
int tmp = array[i];

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return (j);
array[i] = array[j];
array[j] = tmp;
print_array(array, (size_t)j + 1);
}
}

/**
* quick_sort_recursive - recursive function to perform Quick sort
* @array: array to sort
* @low: starting index of the subarray
* @high: ending index of the subarray
*/
void quick_sort_recursive(int *array, int low, int high)
{
if (low < high)
{
int pivot_index = partition(array, low, high);
quick_sort_recursive(array, low, pivot_index);
quick_sort_recursive(array, pivot_index + 1, high);
}
}

