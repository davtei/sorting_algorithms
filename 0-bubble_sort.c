#include "sort.h"

/**
 * swap_int - function that swaps two integers in an array.
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
 * bubble_sort - function that uses the Bubble sort algorithm to sort an
 * array of integers in ascending order.
 * The array is printed each time there is a swapping of two elements
 * @array: array to sort
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, last_unsorted_index = size - 1;
	bool is_sorted = false;

	if (array == NULL || size < 2)
		return;

	while (!is_sorted)
	{
		is_sorted = true;
		for (i = 0; i < last_unsorted_index; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				is_sorted = false;
			}
		}
		last_unsorted_index--;
	}
}
