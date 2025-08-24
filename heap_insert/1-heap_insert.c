#include "binary_trees.h"

/**
 * heap_insert - puts a value in the heap
 * @root: pointer to the root
 * @value: the value to put
 * Return: the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent, *current;
	int tmp;

	if (root == NULL)
		return (NULL);

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_parent(*root);
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Bubble up to maintain max heap property */
	current = new_node;
	while (current->parent != NULL && current->n > current->parent->n)
	{
		tmp = current->n;
		current->n = current->parent->n;
		current->parent->n = tmp;
		current = current->parent;
	}

	return (new_node);
}

/**
 * find_parent - finds the parent node for the new node
 * @root: the root of the heap
 * Return: the parent node where to insert
 */
heap_t *find_parent(heap_t *root)
{
	heap_t **args;
	int start = 0, end = 0, size = 1024;
	heap_t *node;

	args = malloc(sizeof(heap_t *) * size);
	if (args == NULL)
		return (root);

	args[end++] = root;

	while (start < end)
	{
		node = args[start++];

		/* If this node has space for a child, return it */
		if (node->left == NULL || node->right == NULL)
		{
			free(args);
			return (node);
		}

		/* Add children to queue for level-order traversal */
		args[end++] = node->left;
		args[end++] = node->right;
	}

	free(args);
	return (root);
} 
