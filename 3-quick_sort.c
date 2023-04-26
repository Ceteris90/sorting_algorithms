#include "sort.h"

/**
 * quicksort_helper - sorts an array of integers using the Quick sort algorithm
 * @array: the array to sort
 * @lo: the lowest index of the partition being sorted
 * @hi: the highest index of the partition being sorted
 * @size: the size of the array
 *
 * Return: void
 */
void quicksort_helper(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using t
 *
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quicksort_helper(array, 0, size - 1, size);
}

/**
 * quicksort_helper - recursive helper function for quick_sort
 * @array: the array of integers to sort
 * @lo: the starting index of the partition being sorted
 * @hi: the ending index of the partition being sorted
 * @size: the size of the array
 */
void quicksort_helper(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int p = partition(array, lo, hi, size);

		quicksort_helper(array, lo, p - 1, size);
		quicksort_helper(array, p + 1, hi, size);
	}
}

/**
 * partition - Lomuto partition scheme
 * @array: the array of integers to sort
 * @lo: the starting index of the partition being sorted
 * @hi: the ending index of the partition being sorted
 * @size: the size of the array
 * Return: the index of the pivot element
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo - 1, j, temp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/* Swap the elements */
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
