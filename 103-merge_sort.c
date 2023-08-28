#include "sort.h"

/**
* merge_sort - sorts an array with the Merge Sort algorithm
* @array: array of integers to sort
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
int *temp_array;

if (!array || size < 2)
return;

temp_array = malloc(sizeof(int) * size);

merge_sort_recursive(temp_array, array, 0, size);
free(temp_array);
}

/**
* merge_subarray - merges subarrays
* @temp: temporary array for merging
* @array: array to merge
* @left: index of the left element
* @middle: index of the middle element
* @right: index of the right element
*/
void merge_subarray(int *temp, int *array, size_t left,
size_t middle, size_t right)
{
size_t i, j, k = 0;

for (i = left, j = middle; i < middle && j < right; k++)
{
if (array[i] < array[j])
temp[k] = array[i++];
else
temp[k] = array[j++];
}

while (i < middle)
temp[k++] = array[i++];
while (j < right)
temp[k++] = array[j++];

for (k = left, i = 0; k < right; k++)
array[k] = temp[i++];
}

/**
* merge_sort_recursive - recursive function that merge sorts an array
* @temp: temporary array for merging
* @array: array to merge sort
* @left: index of the left element
* @right: index of the right element
*/
void merge_sort_recursive(int *temp, int *array, size_t left, size_t right)
{
size_t middle;

if (right - left > 1)
{
middle = (right - left) / 2 + left;
merge_sort_recursive(temp, array, left, middle);
merge_sort_recursive(temp, array, middle, right);
merge_subarray(temp, array, left, middle, right);
}
}
