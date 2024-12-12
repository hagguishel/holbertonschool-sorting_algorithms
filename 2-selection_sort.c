#include "sort.h"

/**
 * selection_sort - sorts an array using the Selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int mini;
	int mini_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		j = i + 1;
		mini = array[i];
		while (j < size)
		{
			if (array[j] < mini)
			{
				mini = array[j];
				mini_index = j;
			}
			j++;
		}
		temp = array[i];
		array[i] = array[mini_index];
		array[mini_index] = temp;
		print_array(array, size);
		i++;
	}
}
