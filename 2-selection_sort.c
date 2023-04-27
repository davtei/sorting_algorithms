#include "sort.h"

/**
 * swap_ints - function that swaps two integers in an array.
 * @first: first integer
 * @second: second integer
*/
void swap_ints(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * selection_sort - function that sorts an array of integers in ascending
 *	order using the Selection sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * The array is printed each time there is a swapping of two elements
 */
void selection_sort(int *array, size_t size)
{
	int *min_val;   /* A pointer to the minimum value in the array. */
	size_t i, j;

	/* Check for null pointers or empty array. */
	if (array == NULL || size < 2)
		return;

	/* Iterate through the array, selecting the minimum value each time. */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the first value is the minimum. */
		min_val = array + i;

		/* Find the actual minimum value in the remaining unsorted portion. */
		for (j = i + 1; j < size; j++)
			min_val = (array[j] < *min_val) ? (array + j) : min_val;

		/* Swap the minimum value with the current position, if necessary. */
		if ((array + i) != min_val)
		{
			swap_ints(array + i, min_val);
			print_array(array, size);
		}
	}
}
