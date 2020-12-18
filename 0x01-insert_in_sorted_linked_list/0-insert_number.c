#include "lists.h"
/**
 * insert_node - function that inserts a number into a sorted linked list.
 * @head: Double pointer to linked list head.
 * @number: Integer to add into a linked list.
 * Return: NULL in failure otherwhise will return the adress of the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *h = NULL;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	h = *head;
	new_node->n = number;
	new_node->next = NULL;

	while (h != NULL)
	{
		if (h->next)
		{
			if (h->n > number)
			{
				new_node->next = h;
				(*head) = new_node;
				break;
			}
			if (h->n < number && h->next->n > number)
			{
				new_node->next = h->next;
				h->next = new_node;
				break;
			}
		}
		if (h->next == NULL)
		{
			h->next = new_node;
			break;
		}
		h = h->next;
	}
	return (new_node);
}
