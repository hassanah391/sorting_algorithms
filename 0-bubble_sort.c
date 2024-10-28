#include "sort.h"


/**
 * bubble_sort - sorts an array of unsorted numbers using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int is_sorted;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		is_sorted = 1;
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swap(array, j - 1, j);
				print_array(array, size);
				is_sorted = 0;
			}
		}
		if (is_sorted == 1)
			break;
	}
}


/**
 * swap - swap two elements in an array
 * @array: an array of integers
 * @index1: index of first element
 * @index2: index of seconed element
 */
void swap(int *array, int index1, int index2)
{
	int temp;

	temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}
