#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pop(levelorder_queue_t **head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new node for levelorder_queue_t
 * @node: binary tree node for the new node to contain
 * Return: If an error occurs, NULL, else a pointer to the new node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a queue for levelorder_queue_t
 * @head: pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node
 *             and pushes its children into a levelorder_queue_t queue.
 * @node: binary tree node to print and push
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 * @func: pointer to the function to call on @node
 *
 * Description: Exits with a status code of 1 on malloc failure
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_nod;

	func(node->n);
	if (node->left != NULL)
	{
		new_nod = create_node(node->left);
		if (new_nod == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_nod;
		*tail = new_nod;
	}
	if (node->right != NULL)
	{
		new_nod = create_node(node->right);
		if (new_nod == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_nod;
		*tail = new_nod;
	}
}

/**
 * pop - Pops head of levelorder_queue_t
 * @head: double pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree by using
 *                          level-order traversal method
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
