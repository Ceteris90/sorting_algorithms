#include "sort.h"

/**
 * print_list - prints the contents of a doubly linked list of intege
 * @list: pointer to the head of the list
 */
void print_list(const listint_t *list)
{
    while (list != NULL)
    {
        printf("%d", list->n);
        if (list->next != NULL)
            printf(", ");
        list = list->next;
    }
    printf("\n");
}
