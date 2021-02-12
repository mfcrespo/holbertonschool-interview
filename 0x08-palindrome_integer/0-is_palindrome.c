#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - function that checks whether or not a
 * given unsigned integer is a palindrome.
 * @n: unsigned integer
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int remainder, number, sum = 0;

	for (number = n; n != 0; n = n / 10)
	{
		remainder = n % 10;
		sum = sum * 10 + remainder;
	}
	if (number == sum)
		return (1);
	else
		return (0);
}
