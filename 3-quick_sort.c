#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - partitions the array using Lomuto scheme
 * @array: array to take in
 * @start: start of array
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int partition(int *array, int start, int end, int size)
{
    int pivot = array[end];
    int i = start - 1;
    int j;

    for (j = start; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap_int(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (i + 1 != end)
    {
        swap_int(&array[i + 1], &array[end]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quickSort_helper - quick sorts with recursion
 * @array: array to sort through
 * @start: start of array or subarray
 * @end: end of array or subarray
 * @size: size of full array
 */
void quickSort_helper(int *array, int start, int end, int size)
{
    if (start < end)
    {
        int pivot = partition(array, start, end, size);
        quickSort_helper(array, start, pivot - 1, size);
        quickSort_helper(array, pivot + 1, end, size);
    }
}

/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quickSort_helper(array, 0, size - 1, size);
}
