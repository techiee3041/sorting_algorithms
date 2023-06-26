#include "deck.h"

/**
 * sort_deck - sorts a deck of card
 * @deck: list to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t len;
	deck_node_t *o, *t, *th, *fo;

	len = list_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;

	curr = *deck;
	while (curr)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
			o = curr->prev->prev;
			t = curr->prev;
			th = curr;
			fo = curr->next;

			t->next = fo;
			if (fo)
				fo->prev = t;
			th->next = t;
			th->prev = o;
			if (o)
				o->next = th;
			else
				*deck = th;
			t->prev = th;
			curr = *deck;
			continue;
		}
		else
			curr = curr->next;
	}
}

/**
 * card_value - returns the value of a card
 * @node: card in a deck
 * Return: print value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	char *v[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *ks[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int x, kdv = 0;

	for (x = 1; x <= 13; x++)
	{
		if (!_strcmp(node->card->value, v[x - 1]))
			kdv = x;
	}

	for (x = 1; x <= 4; x++)
	{
		if (!_strcmp(ks[node->card->kind], ks[x - 1]))
			kdv = kdv + (13 * x);
	}

	return (kdv);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: answer always
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck -  returns length of list
 * @list: head of poinetr
 * Return: ...
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t l = 0;

	while (list)
	{
		l++;
		list = list->next;
	}
	return (l);
}
