#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorts an array using the Quicksort algorithm
 * @array: int array to sort
 * @size: array size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort Algorithm
 * @array: sort array
 * @left: index of element on the left
 * @right: index element on the right
 * @size: array size
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv + 1, right, size);
	}
}

/**
 * partition - gives a pivot index for Quicksort
 * @array: array to find the pivot from
 * @left: index of element on the left
 * @right: index of element on the right
 * @size: array size
 *
 * Return: the index of the pivot element
 */
int partition(int *array, int left, int right, size_t size)
{
	int tmp, i;
	int j;

	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] < array[right])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
