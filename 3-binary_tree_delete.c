#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @ptree: pointer to the root node of the tree to be deleted
 * Return: void
 */
void binary_tree_delete(binary_tree_t *ptree)
{
	if (ptree)
	{
		binary_tree_delete(ptree->left);
		binary_tree_delete(ptree->right);
		free(ptree);
	}
}
