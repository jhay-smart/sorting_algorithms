#include "sort.h"

/**
 * list_len - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_nodes - function swaps nodes at pointer pt with the following node
 * @list: head of list
 * @pt: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **pt)
{
	listint_t *one, *two, *three, *four;

	one = (*pt)->prev;
	two = *pt;
	three = (*pt)->next;
	four = (*pt)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*pt = three;
}

/**
 *  cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *pt;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	pt = *list;
	while (!sorted)
	{
		sorted = 1;
		while (pt->next)
		{
			if (pt->n > pt->next->n)
			{
				sorted = 0;
				switch_nodes(list, &pt);
				print_list(*list);
			}
			else
				pt = pt->next;
		}
		if (sorted)
			break;
		pt = pt->prev;
		while (pt->prev)
		{
			if (pt->n < pt->prev->n)
			{
				sorted = 0;
				pt = pt->prev;
				switch_nodes(list, &pt);
				print_list(*list);
			}
			else
				pt = pt->prev;
		}
	}
}
