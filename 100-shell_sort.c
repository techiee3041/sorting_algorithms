#include "sort.h"

/**
 * shell_sort - sort array
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
*/

void shell_sort(int *array, size_t size)
{
	int x = 0, y = 0, s = 1, a = 0;

	if (!array || size < 2)
		return;

	while (s < (int)size / 3)
		s = s * 3 + 1;
	while (s > 0)
	{
		y = s;
		while (y < (int)size)
		{
			a = array[y];
			x = y;
			while (x > s - 1 && array[x - s] >= a)
			{
				array[x] = array[x - s];
				x = x - s;
			}
		array[x] = a;
		y++;
	}
	print_array(array, size);
	s = (s - 1) / 3;
	}
}

