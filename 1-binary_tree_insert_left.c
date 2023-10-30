#include "binary_trees.h"

/**
 * binary_tree_insert_left - It inserts a node as a left-child in a binary tree
 * @parent: A pointer to the node where we insert the left-child
 * @value: The value to be stored in the new node
 * Return: pointer to the new node otherwise null on error
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
