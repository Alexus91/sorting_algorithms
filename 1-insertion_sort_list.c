#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		listint_t *temp = curr->next;

		while (curr->prev && curr->n < curr->prev->n)
		{
			listint_t *prev = curr->prev;
			listint_t *next = curr->next;

			if (prev->prev)
				prev->prev->next = curr;
			else
				*list = curr;
			curr->prev = prev->prev;
			prev->next = next;

			if (next)
				next->prev = prev;
			curr->next = prev;
			prev->prev = curr;
			print_list(*list);
		}
		curr = temp;
	}
}
