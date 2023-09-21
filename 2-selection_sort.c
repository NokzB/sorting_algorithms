#include "sort.h"

/**
 * swap - function to swap two elements in an array
 * @a: the first element to swap
 * @b: the second element to swap
 *
 * Return: no return
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - a function that sorts an array of elements
 *			using the Selection Sort Algorithm
 * @array: the array to be sorted
 * @size: the length of the array
 *
 * Return: a sorted array
 */
void selection_sort(int *array, size_t size)
{
	int *min_idx;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; j++)
			min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;
		if ((array + i) != min_idx)
		{
			swap(array + i, min_idx);
			print_array(array, size);
		}
	}

}
