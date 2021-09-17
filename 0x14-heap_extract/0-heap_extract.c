#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap - swaps two values in memory
 * @a: pointer to first value
 * @b: pointer to second value
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * heap_height - calculate the height of a heap
 * @root: heap's root node
 * Return: the height of the tree
 */
int heap_height(heap_t *root)
{
	int left, right;

	if (root == NULL)
		return (0);
	left = heap_height(root->left);
	right = heap_height(root->right);
	return (left > right ? left + 1 : right + 1);
}

/**
 * last_node - return the last level orderer node
 * @root: heap's root node
 * @height: heap's height
 * Return: pointer to node, NULL if fails
 */
heap_t *last_node(heap_t *root, int height)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (height == 1)
		return (root);
	left = last_node(root->left, height - 1);
	right = last_node(root->right, height - 1);
	return (right == NULL ? left : right);
}

/**
 * fix_heap - return the last level orderer node
 * @root: heap's root node
 * Return: pointer to node, NULL if fails
 */
void fix_heap(heap_t *root)
{
	heap_t *node, *_swap;

	for (node = _swap = root; node != NULL; node = _swap)
	{
		if (node->right && node->left)
		{
			if (node->right->n > node->left->n && node->right->n > node->n)
				_swap = node->right;
			else if (node->left->n > node->right->n && node->left->n > node->n)
				_swap = node->left;
		}
		else if (node->right && node->right->n > node->n)
			_swap = node->right;
		else if (node->left && node->left->n > node->n)
			_swap = node->left;
		else
			break;
		swap(&_swap->n, &node->n);
	}
}
/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: heap's root node
 * Return: the value of extracted node on success, 0 if not
 */
int heap_extract(heap_t **root)
{
	int extracted_value, height;
	heap_t *node;

	if (root == NULL || *root == NULL)
		return (0);
	extracted_value = (*root)->n;
	height = heap_height(*root);
	node = last_node(*root, height);
	if (height == 1)
	{
		free(node);
		*root = NULL;
		return (extracted_value);
	}
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	(*root)->n = node->n;
	free(node);
	fix_heap(*root);
	return (extracted_value);
}
