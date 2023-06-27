#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, new_size, len;
	int temp;

	if (array == NULL || size < 2)
		return;

	len = size;
	while (len > 0)
	{
		new_size = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				new_size = i + 1;
				print_array(array, size);
			}
		}
		len = new_size;
	}
}
