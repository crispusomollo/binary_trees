#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a binary search tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new_nod;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new_nod = binary_tree_node(curr, value);
			if (new_nod == NULL)
				return (NULL);
			return (*tree = new_nod);
		}

		if (value < curr->n)
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new_nod = binary_tree_node(curr, value);
			if (new_nod == NULL)
				return (NULL);
			return (curr->left = new_nod);
		}
		if (value > curr->n)
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new_nod = binary_tree_node(curr, value);
			if (new_nod == NULL)
				return (NULL);
			return (curr->right = new_nod);
		}
	}
	return (NULL);
}
