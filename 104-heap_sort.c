#include "sort.h"

/**
* swap - Swaps two integers in an array
* @a: First integer
* @b: Second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* sift_down - Performs sift-down operation on a heap node
* @array: Array representing the heap
* @size: Size of the heap
* @index: Index of the node to sift down
* @heap_size: Size of the current heap being worked on
*/
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
size_t largest = index;
size_t left = 2 * index + 1;
size_t right = 2 * index + 2;

if (left < heap_size && array[left] > array[largest])
largest = left;

if (right < heap_size && array[right] > array[largest])
largest = right;

if (largest != index)
{
swap(&array[index], &array[largest]);
print_array(array, size);
sift_down(array, size, largest, heap_size);
}
}

/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: Array to be sorted
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
size_t i;
if (!array || size < 2)
return;

for (i = size / 2; i != 0; i--)
{
sift_down(array, size, i - 1, size);
}

for (i = size; i > 1; i--)
{
swap(&array[0], &array[i - 1]);
print_array(array, size);
sift_down(array, size, 0, i - 1);
}
}
