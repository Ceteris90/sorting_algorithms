#include "sort.h"

void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in asc
 *
 * @list: double pointer to the head of the linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL, *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = start = (*list); current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &current->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		end = current;

		for (current = end->prev; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &current->prev, &current);
				swapped = 1;
				print_list(*list);
			}
		}
		start = current->next;
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the linked list
 * @n1: pointer to the first node
 * @n2: pointer to the second node
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	tmp1 = (*n1)->prev;
	tmp2 = (*n2)->next;
	(*n1)->prev = (*n2);
	(*n2)->next = (*n1);
	if (tmp1 != NULL)
		tmp1->next = (*n2);
	if (tmp2 != NULL)
		tmp2->prev = (*n1);

	(*n1)->next = tmp2;
	(*n2)->prev = tmp1;
	if ((*n1)->prev == NULL)
		*list = (*n1);
}


