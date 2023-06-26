#include "sort.h"

/**
 * merge_sort -  Merge Sort algorithm
 * @array: array  to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - merge sorts an array
 * @arr: copy array
 * @array: array to merge sort
 * @left: left element
 * @right: right element
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = (right - left) / 2 + left;
		merge_recursion(arr, array, left, mid);
		merge_recursion(arr, array, mid, right);
		merge_subarray(arr, array, left, mid, right);
	}
}

/**
 * merge_subarray - merges subarrays
 * @arr: duplicate array
 * @array: array to merge
 * @left: left element
 * @mid:  middle element
 * @right: right element
 */
void merge_subarray(int *arr, int *array, size_t left,
		size_t mid, size_t right)
{
	size_t u, xx, pp = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid  - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (u = left, xx = mid; u < mid && xx < right; pp++)
	{
		if (array[u] < array[xx])
			arr[pp] = array[u++];
		else
			arr[pp] = array[xx++];
	}

	while (u < mid)
		arr[pp++] = array[u++];
	while (xx < right)
		arr[pp++] = array[xx++];

	for (pp = left, u = 0; pp < right; pp++)
		array[pp] = arr[u++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

