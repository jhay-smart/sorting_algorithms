#include "sort.h"

/**
 * swap - This swaps 2 nodes in a doubly-linked list
 * @a: The address of first node
 * @j: The address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *j)
{
	if (a->prev)
		a->prev->next = j;
	if (j->next)
		j->next->prev = a;
	a->next = j->next;
	j->prev = a->prev;
	a->prev = j;
	j->next = a;

}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *t;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		t = i;
		i = i->next;
		while (t && t->prev)
		{
			if (t->prev->n > t->n)
			{
				swap(t->prev, t);
				if (!t->prev)
					*list = t;
				print_list((const listint_t *)*list);
			}
			else
				t = t->prev;
		}

	}
}
