#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: pointer to the node to check
 * Return: If the node is a root - 1
 *         Otherwise - 0 if node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL || node->parent == NULL)
		return (1);

	return (0);
}
