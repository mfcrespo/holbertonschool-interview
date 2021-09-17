#include "search_algos.h"

/**
 * print_array - print element to array
 * @array: is a pointer to the first element to the array
 * @from: number of element in array
 * @to: number of element in array
 */
void print_array(int *array, size_t from, size_t to)
{
	unsigned int i;

	printf("Searching in array: ");
	for (i = from; i < to; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%i\n", array[i]);
}

/**
 * ad_binary - print the message
 * @array: is a pointer to the first element of the array to search in array
 * @left: index to start search
 * @right: index to end search
 * @value: value to find
 *
 * Return: index
 */
int ad_binary(int *array, size_t left, size_t right, int value)
{
	if (left <= right)
	{
		int mid = (left + right) / 2;

		print_array(array, left, right);
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		else if (array[mid] >= value)
			return (ad_binary(array, left, mid, value));
		else
			return (ad_binary(array, mid + 1, right, value));
	}
	return (-1);
}

/**
 * advanced_binary - function that searches for a value in
 * a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: If value is not present in array or if array is NULL,
 * your function must return -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (!value || array == NULL)
	{
		return (-1);
		}

	return (ad_binary(array, 0, size - 1, value));
}
