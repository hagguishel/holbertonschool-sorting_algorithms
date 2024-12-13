#include <stddef.h>
#include "sort.h"

/**
 * quick_sort_rec - Recursively applies the quicksort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_partition(array, low, high, size);
        quick_sort_rec(array, low, pivot_index - 1, size);
        quick_sort_rec(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers using quicksort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    quick_sort_rec(array, 0, size - 1, size);
}
