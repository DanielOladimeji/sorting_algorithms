#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linkedlist int in ascending order
 * @list: double pointer to the list to be sorted
 *
 * Return: void
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* swap nodes */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			/* move back through list */
			print_list(*list);
		}
		current = current->next;
	}
}
