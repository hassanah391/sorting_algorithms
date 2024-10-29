#include "sort.h"

/**
 * swapNodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @first: First node to swap
 * @second: Second node to swap
 *
 * Return: Pointer to the smaller node (new position)
 */
listint_t *swapNodes(listint_t **list, listint_t *first, listint_t *second)
{
	listint_t *tmp = second->next;

	if (!first || !second || !list || !*list)
		return (NULL);

	/* Handle the previous connection of first node */
	if (first->prev)
		first->prev->next = second;
	else
		*list = second;

	/* Set up second node's connections */
	second->prev = first->prev;
	second->next = first;

	/* Set up first node's connections */
	first->prev = second;
	first->next = tmp;

	/* Handle the next connection */
	if (tmp)
		tmp->prev = first;

	return (second);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tail;
	int swapped = 1;

	/* Check for NULL pointers and single-node list */
	if (!list || !*list || !(*list)->next)
		return;

	/* Find the tail of the list */
	for (tail = *list; tail->next; tail = tail->next)
		;

	while (swapped)
	{
		swapped = 0;

		/* Forward pass */
		for (current = *list; current->next != NULL; )
		{
			if (current->n > current->next->n)
			{
				current = swapNodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		/* Backward pass */
		for (current = tail; current->prev != NULL; )
		{
			if (current->n < current->prev->n)
			{
				current = swapNodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
