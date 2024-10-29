#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * Shell sort algorithm with Knuth sequence
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Description: Implements Shell sort using the Knuth sequence(n+1 = n * 3 + 1)
 * The sequence goes like: 1, 4, 13, 40, 121, ...
 * The array is printed after each gap reduction.
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Check for invalid input */
	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap using Knuth sequence: n+1 = n * 3 + 1 */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Main Shell sort loop */
	while (gap > 0)
	{
		/* Perform insertion sort with current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			/* Move elements that are greater than temp to gap positions ahead */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		/* Print array after each gap reduction */
		print_array(array, size);

		/* Calculate next gap using Knuth sequence reduction */
		gap = (gap - 1) / 3;
	}
}
