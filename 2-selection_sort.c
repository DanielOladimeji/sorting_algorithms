#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: sort array
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
