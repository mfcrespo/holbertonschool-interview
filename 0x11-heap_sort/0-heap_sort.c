#include "sort.h"

/**
* swap - swaps two positions
* @arrayA: first array
* @arrayB: second array
* Return: Void
*/

void swap(int *arrayA, int *arrayB)
{
	int temp;

	temp = *arrayA;
	*arrayA = *arrayB;
	*arrayB = temp;
}

/**
* heap - makes array into a heap
* @arrayPtr: pointer to integer array
* @size: size of the array variable
* @maxPoint: Max point
* @length: size of the array in heap_sort function
*/

void heap(int *arrayPtr, int size, int maxPoint, int length)
{
	int maxTmp = maxPoint; /* Save the maxPoint to use and compare later */
	int left = (2 * maxPoint) + 1;
	int right = (2 * maxPoint) + 2;

	if (left < size && arrayPtr[maxTmp] < arrayPtr[left])
		maxTmp = left;

	if (right < size && arrayPtr[maxTmp] < arrayPtr[right])
		maxTmp = right;

	if (maxTmp != maxPoint)
	{
		swap(&arrayPtr[maxPoint], &arrayPtr[maxTmp]);
		print_array(arrayPtr, length);
		heap(arrayPtr, size, maxTmp, length);
	}
}

/**
 * heap_sort - sorts an array of integers with heap sorting
 * @array: pointer to array
 * @size: size of the array
 * Return: Void
 */

void heap_sort(int *array, size_t size)
{
	int maxPoint;

	if (!size || !array)
		return;

	for (maxPoint = (size / 2) - 1; maxPoint >= 0; maxPoint--)
		heap(array, size, maxPoint, size);

	for (maxPoint = size - 1; maxPoint > 0; maxPoint--)
	{
		if (array[0] >= array[maxPoint])
		{
			swap(&array[0], &array[maxPoint]);
			print_array(array, size);
		}
		heap(array, maxPoint, 0, size);
	}
}
