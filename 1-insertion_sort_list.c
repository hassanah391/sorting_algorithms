#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = (*list)->next;
	while (temp != NULL)
	{
		current = temp;
		temp = temp->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current, current->prev);
			print_list((*list));
		}
	}
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @head: Double pointer to the head of the list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{

	listint_t *temp;

	if (node1 == node2 || node1 == NULL || node2 == NULL)
		return;

	if (*head == node1)
		*head = node2;

	else if (*head == node2)
		*head = node1;


	if (node1->prev)
		node1->prev->next = node2;

	if (node2->prev)
		node2->prev->next = node1;

	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;


	if (node1->next)
		node1->next->prev = node2;

	if (node2->next)
		node2->next->prev = node1;

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
}
