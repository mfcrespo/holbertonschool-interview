#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - binary tree AVL
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree
 **/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *sortTree = NULL;

	sortTree = recursiveTree(array, 0, (int)size - 1);
	if (!sortTree)
	{
		return (NULL);
	}
	return (sortTree);
}

/**
 * create_node - Creates a new binary node
 * @n: Value in the new node.
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(int n)
{
	avl_t *node = NULL;

	if (n == 0)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = n;
	return (node);
}

/**
 * recursiveTree - add node using this function as recursive method
 * @array: array.
 * @low: lower node.
 * @high: higher node.
 * Return: tree
 */
avl_t *recursiveTree(int *array, int low, int high)
{
	avl_t *left = NULL, *right = NULL, *parent = NULL;
	size_t n = 0;

	if (low > high)
		return (NULL);
	n = (low + high) / 2;
	left = recursiveTree(array, low, n - 1);
	right = recursiveTree(array, n + 1, high);
	parent = create_node(array[n]);
	if (!parent)
		return (NULL);
	parent->left = left;
	parent->right = right;
	if (left)
		left->parent = parent;
	if (right)
		right->parent = parent;
	return (parent);
}
