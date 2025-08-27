#include "binary_trees.h"

/**
 * find_insertion_parent - finds the first node missing a child (BFS)
 * @root: pointer to the root node
 * Return: Parent node where the new node should be inserted
 */
heap_t *find_insertion_parent(heap_t *root)
{
	int front = 0, rear = 0;
	heap_t **queue = malloc(sizeof(heap_t *) * 1024);

	if (queue == NULL)
		return (NULL);

	queue[rear++] = root; /* Enqueue root */

	while (front < rear)
	{
		heap_t *current = queue[front++]; /* Dequeue */

		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}

		if (current->left)
			queue[rear++] = current->left; /* Enqueue left child */
		if (current->right)
			queue[rear++] = current->right; /* Enqueue right child */
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - puts a value in the heap
 * @root: pointer to the root
 * @value: the value to put
 * Return: the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		new_node = malloc(sizeof(heap_t));
		if (new_node == NULL)
			return (NULL);
		new_node->n = value;
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		*root = new_node;
		return (new_node);
	}

	parent = find_insertion_parent(*root);
	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Bubble up to maintain max heap property */
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		int tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}