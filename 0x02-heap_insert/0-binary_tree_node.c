#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create.
 * @value: is the value to put in the new node
 *         When created, a node does not have any children.
 * Return: a pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Declarate Variable that pointer to structure */
	binary_tree_t *nodeNew;
	/* Allocate Memory to nodeNew with a size as structure */
	nodeNew = malloc(sizeof(binary_tree_t));
	/* Validate is null */
	if (nodeNew == NULL)
		return (NULL);
	/* add nodeNew  */
	nodeNew->left = nodeNew->right = NULL;
	nodeNew->n = value;
	nodeNew->parent = parent;
	/* Return nodenew on the tree */
	return (nodeNew);
}
