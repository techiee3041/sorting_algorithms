#include "sort.h"
/**
 *selection_sort- print the selection sortt
 *@array: array to be sorted
 *@size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, k;
	int buff;

	if (!array || !size)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = size - 1, k = x + 1; y > x; y--)
		{
			if (array[y] < array[k])
			{
				k = y;
			}
		}
		if (array[x] > array[k])
		{
			buff = array[x];
			array[x] = array[k];
			array[k] = buff;
			print_array(array, size);
		}
	}
}
