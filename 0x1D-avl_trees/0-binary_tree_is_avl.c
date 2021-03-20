#include <limits.h>
#include <stddef.h>
#include "binary_trees.h"

/**
 * bst_h - Checks if valid BST
 * @tree: Pointer to root node being checked
 * @min: Int min
 * @max: Int max
 *
 * Return: 1 if valid BST, 0 if not
 */
int bst_h(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_h(tree->left, min, tree->n - 1) &&
		bst_h(tree->right, tree->n + 1, max));
}

/**
 * bst - Checks if valid BST
 * @tree: Pointer to root node of tree to check
 *
 * Return: 1 if valid BST, 0 if not
 */
int bst(const binary_tree_t *tree)
{
	return (bst_h(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to root node of tree to check
 *
 * Return: 1 if valid BST, 0 if not or NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (tree ? bst(tree) : 0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_avl - Determine if binary tree is an AVL or not
 * @tree: Pointer to root node of binary tree
 *
 * Return: 1 if tree is an AVL, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;
	size_t difference;

	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	height_left = tree->left ? binary_tree_height(tree->left) : 0;
	height_right = tree->right ? binary_tree_height(tree->right) : 0;

	if (height_left > height_right)
		difference = height_left - height_right;
	else
		difference = height_right - height_left;

	if (difference > 1)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
