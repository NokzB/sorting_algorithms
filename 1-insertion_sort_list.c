#include "sort.h"
/**
 * insertion_sort_list - function to sort a doubly
 *		linked list using Insertion Sort
 * @list: a double pointer to the list of values
 *
 * Return: A sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *change;

	if (!list || !*list)
		return;

	current = *list;
	while ((current = current->next))
	{
		change = current;
		while (change->prev && change->n < change->prev->n)
		{
			previous = change->prev;
			if (change->next)
				change->next->prev = previous;
			if (previous->prev)
				previous->prev->next = change;
			else
				*list = change;
			previous->next = change->next;
			change->prev = previous->prev;
			change->next = previous;
			previous->prev = change;

			print_list(*list);
		}
	}
}
