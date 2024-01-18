#include "sort.h"

/**
* heapify - Organizes the heap
* @array: Array to sort
* @size: Size of the array
* @index: Index to start the heapify process
* @total_size: Total size of the array (for printing)
*/
void heapify(int *array, size_t size, size_t index, size_t total_size)
{
size_t largest = index;
size_t left = 2 * index + 1;
size_t right = 2 * index + 2;

if (left < size && array[left] > array[largest])
largest = left;

if (right < size && array[right] > array[largest])
largest = right;

if (largest != index)
{
int temp = array[index];
array[index] = array[largest];
array[largest] = temp;

print_array(array, total_size);

heapify(array, size, largest, total_size);
}
}

/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: Array to sort
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

for (int i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);

for (int i = size - 1; i > 0; i--)
{
int temp = array[0];
array[0] = array[i];
array[i] = temp;

print_array(array, size);

heapify(array, i, 0, size);
}
}
