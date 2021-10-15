#include "sort.h"

/**
 * topDownMerge - merge sort
 * @array: Array to be sorted
 * @size: Size of array
 * @mid: Middle index
 * @temp: Temporal array
 * Return: Nothing.
 */
void topDownMerge(int *array, int size, int mid, int *temp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	for (i = 0, j = mid, k = 0; k < size; k++)
	{
		if (j == size)
		{
			temp[k] = array[i];
			i++;
		}
		else if (i == mid)
		{
			temp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			temp[k] = array[j];
			j++;
		}
		else
		{
			temp[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	printf("[Done]: ");
	print_array(temp, size);
}

/**
 * topDownMerge_main - merge sort
 * @array: Array to be sorted
 * @size: Size of array
 * @temp: Temporal array
 * Return: Nothing.
 */
void topDownMerge_main(int *array, size_t size, int *temp)
{
	int mid;

	if (size < 2)
	{
		return;
	}
	mid = (size / 2);
	topDownMerge_main(array, mid, temp);
	topDownMerge_main(array + mid,  size - mid, temp);
	topDownMerge(array, size, mid, temp);
}

/**
 * merge_sort - function to sort an array of integers in ascending order
 * @array: pointer to array
 * @size: size array
 * Return: array of integers in ascending order
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
	{
		return;
	}
	temp = malloc(sizeof(int) * size);
	if (!temp)
	{
		return;
	}
	topDownMerge_main(array, size, temp);
	free(temp);
}
