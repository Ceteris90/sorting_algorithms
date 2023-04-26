#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in as
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;
	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			/* Swap the nodes */
			temp = prev->prev;

			prev->prev = current;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->prev = temp;
			current->next = prev;

			if (temp != NULL)
				temp->next = current;
			else
				*list = current;
			/* Print the list after each swap */
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
