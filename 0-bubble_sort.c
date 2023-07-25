#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, k;
	int tmp;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (k = 0; k < size - i - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
