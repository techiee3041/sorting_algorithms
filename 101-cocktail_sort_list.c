#include "sort.h"

/**
 * list_len - returns length of list
 * @list: head of list
 * Return: always answer
 */
size_t list_len(listint_t *list)
{
	size_t l = 0;

	while (list)
	{
		l++;
		list = list->next;
	}
	return (l);
}

/**
 * switch_nodes - swaps nodes at pointer p with the following node
 * @list: head of the address
 * @p: pointer to address of node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *x, *y, *w, *z;

	x = (*p)->prev;
	y = *p;
	w = (*p)->next;
	z = (*p)->next->next;
	y->next = z;
	if (z)
		z->prev = y;
	w->next = y;
	w->prev = y->prev;
	if (x)
		x->next = w;
	else
		*list = w;
	y->prev = w;
	*p = w;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *x;
	int sorti = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	x = *list;
	while (!sorti)
	{
		sorti = 1;
		while (x->next)
		{
			if (x->n > x->next->n)
			{
				sorti = 0;
				switch_nodes(list, &x);
				print_list(*list);
			}
			else
				x = x->next;
		}
		if (sorti)
			break;
		x = x->prev;
		while (x->prev)
		{
			if (x->n < x->prev->n)
			{
				sorti = 0;
				x = x->prev;
				switch_nodes(list, &x);
				print_list(*list);
			}
			else
				x = x->prev;
		}
	}
}
