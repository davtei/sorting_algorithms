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
 * lomuto_partition -  function takes an array, its size, and the starting and
 * ending indices of a subset to order.
 * The subset is partitioned according to the Lomuto partition scheme,
 * which uses the last element of the subset as the pivot element.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	/* Set the pivot element to the last element of the subset to order */
	int *pivot, above, below;

	pivot = array + right;

	/* Iterate through the subset, moving elements smaller than the pivot */
	/* to the "below" partition. */
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			/* If the current element is smaller than the pivot, swap it */
			/* with the first element of the "above" partition (which is*/
			/* empty) and increment the "above" pointer. */
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	/* Swap the pivot element with the first element of the "above" */
	/* partition, effectively moving it between the "below" and "above" */
	/* partitions. */
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - function implements the quicksort algorithm using the
 * Lomuto partition scheme.
 * It takes an array of integers, and two indices (left and right) which
 * indicates the start and end of the partition to be sorted.
 * If the difference between the right and left indices is greater than 0,
 * it calls the lomuto_partition() function to determine the partition
 * and then recursively calls itself on the sub-partitions.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * The array is printed each time there is a swapping of two elements
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	lomuto_sort(array, size, 0, (size - 1));
}
