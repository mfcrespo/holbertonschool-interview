#include "lists.h"
/**
 * linked_list_size - function that calculates the size of a linked list.
 * @head: A pointer to the head of the list.
 * Return: the size of the list.
 */
int linked_list_size(listint_t **head)
{
	listint_t *h = (*head);
	int size = 0;

	if (head == NULL)
		return (0);

	while (h != NULL)
	{
		size += 1;
		h = h->next;
	}

	return (size);

}
/**
 * copy_linked_list - function that copy a linked list into an array.
 * @head: A pointer to the head of the list.
 * @size: The size of the list.
 * Return: A pointer to the new array otherwhise returns NULL.
 */
int *copy_linked_list(listint_t **head, int size)
{
	listint_t *h = (*head);
	int *newList;
	int i = 0;

	newList = malloc(sizeof(size) * size);
	if (newList == NULL)
		return (NULL);

	for (i = 0; i < size; i++, h = h->next)
	{
		newList[i] = h->n;
	}

	return (newList);
}
/**
 * is_palindrome - function in C that checks if a singly linked
 * list is a palindrome.
 * @head: A pointer to the head of the list.
 * Return: 1 if the list is palindrome, otherwhise will return 0.
 */

int is_palindrome(listint_t **head)
{
	int size;
	int *newList;
	int start = 0;
	int end;

	if (head == NULL)
		return (1);

	size = linked_list_size(head);
	newList = copy_linked_list(head, size);
	end = size - 1;

	for (start = 0; start < end; start++, end--)
	{
		if (newList[start] != newList[end])
		{
			free(newList);
			return (0);
		}
	}

	free(newList);
	return (1);
}
