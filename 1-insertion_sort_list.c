#include "sort.h"

/**
 * swap_nodes - Swap doubly-linked list.
 * @h: A pointeer to head of linked list
 * @n1: first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: A pointer to the head of a doubly-linked 
 * Description: output the list of linked and sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *y, *so, *buff;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	for (y = (*list)->next; y != NULL; y = buff)
	{
		buff = y->next;
		so = y->prev;
		if (so != NULL && y->n < so->n)
		{
			swap_nodes(list, &so, y);
			print_list((const listint_t *)*list);
		}
	}
}
