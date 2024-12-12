#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the Selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[j + 1] && array[j + 1] != 0)
			{
				temp = j;
			}
			j++;
		}
		tmp = array[i];
		array[i] = array[temp];
		array[temp] = tmp;
		print_array(array, size);
		i++;
	}
}
