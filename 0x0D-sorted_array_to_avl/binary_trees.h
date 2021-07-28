#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Function to print tree */
void binary_tree_print(const binary_tree_t *);
/* Prototypes functions */
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *create_node(int n);
avl_t *recursiveTree(int *array, int lower, int high);

#endif /* _SBINARY_TREES_H_ */
