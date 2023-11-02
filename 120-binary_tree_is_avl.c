#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measure the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, your function returns 0, else returns height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lt = 0, rt = 0;

		lt = tree->left ? 1 + height(tree->left) : 1;
		rt = tree->right ? 1 + height(tree->right) : 1;
		return ((lt > rt) ? lt : rt);
	}
	return (0);
}

/**
 * is_avl_helper - Check if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * @low: value of the smallest node visited
 * @high: value of the largest node visited
 *
 * Return: If the tree is a valid AVL tree, return a 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t lehgt, rihgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		lehgt = height(tree->left);
		rihgt = height(tree->right);
		diff = lehgt > rihgt ? lehgt - rihgt : rihgt - lehgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, low, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
