#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts number of leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves
 * Return: number of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t matawi = 0;

	if (tree)
	{
		matawi += (!tree->left && !tree->right) ? 1 : 0;
		matawi += binary_tree_leaves(tree->left);
		matawi += binary_tree_leaves(tree->right);
	}
	return (matawi);
}