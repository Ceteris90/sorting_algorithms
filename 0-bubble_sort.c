#include <stdio.h>
#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array : array to be sorted
 * @size : size of the array
 */
void bubble_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
