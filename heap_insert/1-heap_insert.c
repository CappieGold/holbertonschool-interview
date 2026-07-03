#include "binary_trees.h"

/**
 * tree_size - measures the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: number of nodes in the tree, or 0 if @tree is NULL
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_parent - finds the parent node of the next free slot of a
 *               complete binary tree, given its level-order index
 * @root: pointer to the root node of the tree
 * @index: level-order index (1-based) of the slot to insert into
 *
 * Return: pointer to the parent node of the slot at @index
 */
static heap_t *find_parent(heap_t *root, size_t index)
{
	size_t mask;

	mask = 1;
	while (mask <= index)
		mask <<= 1;
	mask >>= 2;

	while (mask > 1)
	{
		root = (index & mask) ? root->right : root->left;
		mask >>= 1;
	}
	return (root);
}

/**
 * heapify_up - moves a node up a Max Binary Heap until it is not
 *              greater than its parent, restoring the Max Heap property
 * @node: pointer to the node to move up
 *
 * Return: pointer to the node holding the inserted value once the
 * Max Heap property has been restored
 */
static heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->parent->n < node->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;
	size_t index;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = tree_size(*root) + 1;
	parent = find_parent(*root, index);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (index % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
