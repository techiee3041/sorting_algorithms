#include "sort.h"
#include <stdbool.h>

/**
  * insertion_sort_list - Sorts an doubly linked list
  * @list: The doubly linked list to sort
  *
  * Return: answer
  */
void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *t = NULL, *x = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	t = *list;
	while (t->next)
	{
		if (t->n > t->next->n)
		{
			t->next->prev = t->prev;
			if (t->next->prev)
				t->prev->next = t->next;
			else
				*list = t->next;

			t->prev = t->next;
			t->next = t->next->next;
			t->prev->next = t;
			if (t->next)
				t->next->prev = t;

			t = t->prev;
			print_list(*list);

			if (t->prev && t->prev->n > t->n)
			{
				if (!flag)
					x = t->next;
				flag = true;
				t = t->prev;
				continue;
			}
		}
		if (!flag)
			t = t->next;
		else
			t = x, flag = false;
	}
}
