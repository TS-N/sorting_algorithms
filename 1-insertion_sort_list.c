#include "sort.h"

void	node_swap(listint_t *node, listint_t *prev, listint_t **head);

/**
 * insertion_sort_list - insertion sort algo for a linked list
 * @list: the address of the first element of the linked list
 * Return: nothing
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t	*node;
	listint_t	*chkpt;

	if (!list || !*list)
		return;
	chkpt = *list;
	node = *list;
	while (chkpt)
	{
		node = chkpt;
		while (node->prev && node->n < node->prev->n)
		{
			node_swap(node, node->prev, list);
			print_list(*list);
		}
		chkpt = (chkpt)->next;
	}
}

/**
  * node_swap - swap two consecutive node of a double linked list
  * @node: a node that needs to be swapped with the one before
  * @prev: the node before @node, which is equivalent to say prev == node->prev
  * @head: the address of the first element of the list
  **/
void	node_swap(listint_t *node, listint_t *prev, listint_t **head)
{
	if (node && prev)
	{
		if (prev->prev)
			prev->prev->next = node;
		else
			*head = node;
		if (node->next)
			node->next->prev = prev;
		prev->next = node->next;
		node->next = prev;
		node->prev = prev->prev;
		prev->prev = node;
	}
}
