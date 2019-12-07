#include "binary_trees.h"
#include <stdlib.h>
/**
 * insert - inserts node into AVL tree
 * @tree: pointer to root of AVL tree
 * @value: value of node to be inserted
 * Return: pointer to new node
 */
binary_tree_t *insert(avl_t *tree, int value)
{
	int balance;
	binary_tree_t *new, *root;

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);
	if (!tree)
		return (new);
	root = tree;
	if (value < root->n)
		root->left  = insert(root->left, value);
	else if (value > root->n)
		root->right = insert(root->right, value);
	else
		return (new);
	balance = binary_tree_balance(root);
	if (balance > 1 && value < root->left->n)
		return (binary_tree_rotate_right(root));
/* Right Right Case*/
	if (balance < -1 && value > root->right->n)
		return (binary_tree_rotate_left(root));
/* Left Right Case*/
	if (balance > 1 && value > root->left->n)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
/* Right Left Case */
	if (balance < -1 && value < root->right->n)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
/
