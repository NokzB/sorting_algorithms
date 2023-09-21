#include "sort.h"
#include <stdbool.h>
/**
* swap - function to swap elements in an array
* @a: first element to swap
* @b: second element to swap
*
* Return: no return
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
* bubble_sort - function to sort through an array using bubble sort
* @array: the array to sort through
* @size: the length of the array
*
* Return: A sorted array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}
