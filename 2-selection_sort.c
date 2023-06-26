#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The firstto swap.
 * @b: The second to swap.
 */
void swap_ints(int *a, int *b)
{
	int sw;

	sw = *a;
	*a = *b;
	*b = sw;
}

/**
 * selection_sort - Sort an array of integer
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints  swapped arrays.
 */
void selection_sort(int *array, size_t size)
{
	int *x;
	size_t y, k;

	if (!array || size < 2)
		return;

	for (y = 0; y < size - 1; y++)
	{
		x = array + y;
		for (k = x + 1; k < size; k++)
			x = (array[k] < *x) ? (array + k) : x;

		if ((array + y) != x)
		{
			swap_ints(array + y, x);
			print_array(array, size);
		}
	}
}
