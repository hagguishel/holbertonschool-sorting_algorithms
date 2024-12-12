#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *bubble_sort - sorts an arr in ascending order using the Bubble sort algorithm
 *@array: the array to print
 *@size: the size of the array
 *Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp;

	if (array == NULL)
		return;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] > array[j + 1] && array[j + 1] != 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
