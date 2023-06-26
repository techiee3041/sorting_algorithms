#include "sort.h"

/**
* shell_sort - shell sorting
* @array: array of integers
* @size: an array
* Return: nothing
*/
void shell_sort(int *array, size_t size)
{
	size_t count = 0, y, x;
	int buff;

	if (size < 2)
		return;

	while ((count = count * 3 + 1) < size)
		x;

	count = (count - 1) / 3;

	for (; count > 0; count = (count - 1) / 3)
	{
		for (x = count; x < size; x++)
		{
			buff = array[x];
			for (y = x; y >= count && buff <= array[y - count]; y -= count)
				array[y] = array[y - count];
			array[y] = buff;
		}
		print_array(array, size);
	}
}
