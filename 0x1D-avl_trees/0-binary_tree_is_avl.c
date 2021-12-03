#include "binary_trees.h"

/**
 * is_valid_avl - checks if a binary tree is a valid AVL tree
 * @tree: The root of the binary tree
 * @min: The minimum node in the tree
 * @max: The maximum node in the tree
 * @height: The height of the tree
 * Return: true if the binary tree is AVL, false otherwise
 **/
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int height1 = 0, height2 = 0;

	if (tree == NULL)
	{
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
	{
		return (0);
	}

	if (is_valid_avl(tree->left, min, tree->n, &height1) == 0 ||
		is_valid_avl(tree->right, tree->n, max, &height2) == 0)
	{
		return (0);
	}

	*height = ((height1 > height2) ? height1 : height2) + 1;

	if (abs(height1 - height2) > 1)
	{
		return (0);
	}

	return (1);
}


/**
 * binary_tree_is_avl - Returns true if the binary tree is AVL
 * @tree: The root of the binary tree
 * Return: true if the binary tree is AVL, false otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
