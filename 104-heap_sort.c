#include "sort.h"

/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: Array to sort
* @size: Size of the array
*
* Description: This function sorts an array of integers in ascending order
* using the Heap sort algorithm.
*/
void heap_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

int i;

for (i = (int)(size / 2) - 1; i >= 0; i--)


for (i = (int)size - 1; i > 0; i--)
{
int temp = array[0];
array[0] = array[i];
array[i] = temp;

printf("Swap: %d, %d\n", array[0], array[i]);
print_array(array, size);

}
}
