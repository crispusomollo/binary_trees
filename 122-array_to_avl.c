#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in @array
 * Return: pointer to the root node of the created AVL, or NULL upon failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t p, q;

	if (array == NULL)
		return (NULL);

	for (p = 0; p < size; p++)
	{
		for (q = 0; q < p; q++)
		{
			if (array[q] == array[p])
				break;
		}
		if (q == p)
		{
			if (avl_insert(&tree, array[p]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
