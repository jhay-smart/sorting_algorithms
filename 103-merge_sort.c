#include "merge_sort.h"

/*
* @merge: Function to merge two sorted sub-arrays into a single sorted array.
*
* Parameters:
* - array: The original array containing elements
* - temp: Temporary array for merging
* - left: Index of the start of the left sub-array
* - mid: Index of the middle element (end of left sub-array)
* - right: Index of the end of the right sub-array
*/
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid + 1, k = 0;


while (i <= mid && j <= right)
{
if (array[i] <= array[j])
{
temp[k++] = array[i++];
}
else
{
temp[k++] = array[j++];
}

while (i <= mid)
{
temp[k++] = array[i++];
}

while (j <= right)
{
temp[k++] = array[j++];
for (i = left, k = 0; i <= right; ++i, ++k)
{
array[i] = temp[k];
}
}

/*
* @merge_sort_ recursive: function to perform merge sort on a given sub-array.
*
* Parameters:
* - array: The original array containing elements
* - temp: Temporary array for merging
* - left: Index of the start of the sub-array
* - right: Index of the end of the sub-array
*/
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
if (left < right)
{
size_t mid = left + (right - left) / 2;

merge_sort_recursive(array, temp, left, mid);
merge_sort_recursive(array, temp, mid + 1, right);
merge(array, temp, left, mid, right);
}
}

/*
* @merge_sort: Entry point for the merge sort algorithm.
*
* Parameters:
* - array: The array to be sorted
 - size: Number of elements in the array
*/
void merge_sort(int *array, size_t size)
{
int *temp = (int *)malloc(size * sizeof(int));
if (temp == NULL)
{
printf("Memory allocation failed.\n");
return;
}

merge_sort_recursive(array, temp, 0, size - 1);

free(temp);
}
