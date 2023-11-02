#include "binary_trees.h"

/**
 * bst_search - Search for a value in the binary search tree
 * @tree: pointer to root node of the BST to search
 * @value: The value to search for in the BST
 * Return: If the tree is NULL or the value is not found, return NULL
 *         Otherwise return a pointer to the node containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
