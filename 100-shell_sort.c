#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sort an array
 *
 * @array : array to be sorted
 * @size : size of the array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, temp;
	int gap = 1;

	/* Knuth sequence that is smaller than size */
	while (gap < (int)(size / 3))
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		printf("Array at gap %d: ", gap);
		/* perform insertion sort on each gap */
		for (i = gap; i < (int)(size); i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		/* print the current state of the array */

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
