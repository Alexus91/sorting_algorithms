#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: to be sorted
 * @size: Number of elements
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	recursive(array, 0, size - 1, size);
}

/**
 * recursive - Recursive helper function for Quick sort
 *
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @size: amount of elements
 */
void recursive(int *array, int low, int high, size_t size)
{
	int piv;

	if (low < high)
	{
		piv = partition(array, low, high, size);
		recursive(array, low, piv - 1, size);
		recursive(array, piv + 1, high, size);
	}
}
/**
 * partition - partition scheme for Quick sort
 *
 * @array: array to be sorted
 * @low: the low index
 * @high: the high index
 * @s: amount of element
 *
 * Return: the pivot index
 */
int partition(int *array, int low, int high, size_t s)
{
	int piv = array[high];
	int i = low;
	int j;
	int tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < piv)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, s);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (array[i] != array[high])
		print_array(array, s);
	return (i);
}
