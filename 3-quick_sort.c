#include "sort.h"

/**
 * swap - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Implements Lomuto partition scheme
 * @array: Array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts array using Quick sort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    size_t pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}