#include "sort.h"

/**
 * swap_nodes - function that swaps two nodes in a doubly-linked listint_t list
 * @head: points to the head of the list
 * @node1: points to the first pair of nodes to swap
 * @node2: points to the second pair of nodes to swap
*/
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	/* make node1 point to node2's next node */
	(*node1)->next = node2->next;

	/* if node2's next node is not NULL, make it point to node1 */
	if (node2->next != NULL)
		node2->next->prev = *node1;

	/* make node2 point to node1's previous node */
	node2->prev = (*node1)->prev;

	/* make node2 the next node of node1 */
	node2->next = *node1;

	/* if node1's previous node is not NULL, make it point to node2 */
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		/* if node1's previous node is NULL, make node2 the new head node */
		*head = node2;

	/* make node1 point to node2's previous node */
	(*node1)->prev = node2;

	/* update node1 to point to node2's previous node */
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: points to the head of the list
 * The list is printed each time there is a swapping of two nodes
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *tmp, *insert;

	/* Check if list is empty or contains only one node */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Loop through each node in the list starting from the second node */
	for (iterate = (*list)->next; iterate != NULL; iterate = tmp)
	{
		/* Store a pointer to the next node before modifying the list */
		tmp = iterate->next;

		/* Initialize the insert node to the previous node of the current node */
		insert = iterate->prev;

		/* Move the insert node backward while the value of the current node */
		/* is less than the value of the insert node */
		while (insert != NULL && iterate->n < insert->n)
		{
			/* Swap the positions of the current node and the insert node */
			swap_nodes(list, &insert, iterate);

			/* Print the updated list after swapping */
			print_list((const listint_t *)*list);
		}
	}
}
