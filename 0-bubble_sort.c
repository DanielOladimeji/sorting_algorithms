#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: int array 
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp;
	
	/* Check if the size of the array is less than 2 */
	if (size < 2)
		return;

	/* Loop through array */
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + i])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
