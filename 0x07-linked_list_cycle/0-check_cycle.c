#include "lists.h"
/**
 * check_cycle - function in C that checks if a singly linked list 
 * has a cycle in it, like a loop.
 * @list: head of linked list.
 * Return: 0 if false or 1 if true.
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle, *hare;

	turtle = list;
	hare = list;

	if (list == NULL)
		return (0);

	while (hare != NULL && hare->next != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (turtle == hare)
			return (1);
	}
	return (0);
}