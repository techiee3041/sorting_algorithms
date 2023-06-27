#include "sort.h"

/**
 * heapify - array into a heap tree
 * @array: array to a heap
 * @s: size of array
 * @root: index of the sub in the heap
 * @size: ...
 */
void heapify(int *array, size_t s, size_t root, size_t size)
{
	size_t greats, left, right;
	int buf;

	greats = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;
	if (left < s && array[left] > array[greats])
		greats = left;

	if (right < s && array[right] > array[greats])
		greats = right;
	if (greats != root)
	{
		buf = array[root];
		array[root] = array[greats];
		array[greats] = buf;
		print_array(array, size);
		heapify(array, s, greats, size);
	}
}

/**
 * heap_sort - sorts an array in heap
 * @array: array
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	int x;
	int tmp;

	if (size < 2)
		return;

	for (x = size / 2 - 1; x >= 0; x--)
		heapify(array, size, (size_t)x, size);

	for (x = size - 1; x >= 0; x--)
	{
		tmp = array[x];
		array[x] = array[0];
		array[0] = tmp;
		if (x != 0)
			print_array(array, size);
		heapify(array, (size_t)x, 0, size);
	}
}

