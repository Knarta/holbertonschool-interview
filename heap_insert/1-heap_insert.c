#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
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
	int i, size, tmp;

	if (root == NULL)
		return (NULL);

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	size = binary_tree_size(*root);

	i = size + 1;
	parent = *root;

	while (i > 1)
	{
		if (i % 2 == 0)
		{
			if (parent->left == NULL)
				break;
			parent = parent->left;
		}
		else
		{
			if (parent->right == NULL)
				break;
			parent = parent->right;
		}

		i /= 2;	
	}

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}