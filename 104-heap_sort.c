#include "sort.h"

/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: Array to be sorted
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

size_t i;

for (i = size / 2; i != 0; i--)
{
size_t largest = i - 1;
size_t left = 2 * i - 1;
size_t right = 2 * i;

if (left < size && array[left] > array[largest])
largest = left;

if (right < size && array[right] > array[largest])
largest = right;

if (largest != i - 1)
{
int temp = array[i - 1];
array[i - 1] = array[largest];
array[largest] = temp;

print_array(array, size);
}
}

for (i = size; i > 1; i--)
{
int temp = array[0];
array[0] = array[i - 1];
array[i - 1] = temp;

print_array(array, size);

size_t largest = 0;
size_t left = 2 * 0 + 1;
size_t right = 2 * 0 + 2;

if (left < i - 1 && array[left] > array[largest])
largest = left;

if (right < i - 1 && array[right] > array[largest])
largest = right;

if (largest != 0)
{
int temp = array[0];
array[0] = array[largest];
array[largest] = temp;

print_array(array, size);
}
}
}
