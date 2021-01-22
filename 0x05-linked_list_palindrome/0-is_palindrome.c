#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * is_palindrome - function in C that checks if a singly
 * linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *second = NULL;
	listint_t *first = NULL;

	if (head == NULL || *head == NULL)
		return (1);

	second = *head;
	first = *head;

	if (is_palindrome_rec(second, first) == NULL)
		return (0);
	return (1);
}
/**
 * is_palindrome_rec - check is a palindrome recursion
 * @second: pointer to refer the head, the start
 * @first: pointer to move from end to start
 * Return: pointer: palindrome, NULL: not palindrome
 */
listint_t *is_palindrome_rec(listint_t *second, listint_t *first)
{
	listint_t *res = NULL;

	if (first != NULL)
	{
		res = is_palindrome_rec(second, first->next);
		if (res == NULL)
			return (NULL);

		if (res->n != first->n)
			return (NULL);

		if (res->next == NULL)
			return (res);

		return (res->next);
	}

	return (second);
}
