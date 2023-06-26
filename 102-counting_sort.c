#include "sort.h"

/**
 * counting_sort - array with the Counting sort algorithm
 * @array: sort array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
    int *ct, *out_arr, m, n, k, r;
    size_t x, d, alx, tog;

    if (size < 2)
        return;

    m = array[0];
    for (x = 1; x < size; x++)
        if (array[x] > m)
            m = array[x];

    ct = malloc(sizeof(size_t) * (m + 1));
    out_arr = malloc(sizeof(int) * size);

    for (k = 0; k <= m; k++)
        ct[k] = 0;
    for (d = 0; d < size; d++)
    {
        n = array[d];
        ct[n] += 1;
    }
    for (r = 1; r <= m; r++)
        ct[r] += ct[r - 1];
    print_array(ct, m + 1);
    for (alx = 0; alx < size; alx++)
    {
        out_arr[ct[array[alx]] - 1] = array[alx];
        ct[array[alx]]--;
    }
    for (tog = 0; tog < size; tog++)
        array[tog] = out_arr[tog];

    free(ct);
    free(out_arr);
}

