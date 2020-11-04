#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* Prototype Functions */

void binary_tree_print(const binary_tree_t *);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *binary_tree_node(avl_t *parent, int index, int *array);
avl_t *SortedArrayToAVL(int *array, size_t start, size_t end, avl_t *root);

#endif /* _BINARY_TREES_H_ */
