#include "sort.h"

void swap_ints(int *a, int *b);
int l_part(int *array, size_t size, int left, int right);
void q_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - function to swap two integers
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * l_part - Order a subset of an array of integers according to
 *               the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The lowest integer.
 * @right: The highest integer.
 *
 * Return: The final partition index.
 */

int l_part(int *array, size_t size, int left, int right)
{
	int *pivot, greater, less;

	pivot = array + right;
	for (greater = less = left; less < right; less++)
	{
		if (array[less] < *pivot)
		{
			if (greater < less)
			{
				swap_ints(array + less, array + greater);
				print_array(array, size);
			}
			greater++;
		}
	}

	if (array[greater] > *pivot)
	{
		swap_ints(array + greater, pivot);
		print_array(array, size);
	}
	return (greater);
}

/**
 * q_sort - function implemeting the Quicksort Algorithm
 * @array: the array of integers to sort.
 * @size: the length of the array
 * @left: the lowest integer
 * @right: the highest integer
 */
void q_sort(int *array, size_t size, int left, int right)
{
	int pivot;

	if (right - left > 0)
	{
		pivot = l_part(array, size, left, right);
		q_sort(array, size, left, pivot - 1);
		q_sort(array, size, pivot + 1, right);
	}
}

/**
 * quick_sort - sorts an array if integers in ascending order
 *		using the quicksort algorithm
 * @array: the array of integers
 * @size: the length of the array
 *
 * Return: a sorted array of integers
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, size, 0, size - 1);
}
