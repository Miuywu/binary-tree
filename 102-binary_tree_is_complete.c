#include "binary_trees.h"
int i_this_binary_tree_height(const binary_tree_t *tree, int rootval);
int i_binary_tree_preorder(const binary_tree_t *tree, int flag);
int i_recurse(const binary_tree_t *tree);
int i_binary_tree_balance(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: root of tree
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int finalbalance;

	if (!tree)
		return (0);
	finalbalance = i_binary_tree_preorder(tree, 0);
	printf("final = %d\n", finalbalance);

	if (finalbalance < 2 && finalbalance > -1)
		return (1);
	return (0);
}
/**
 * i_binary_tree_preorder - iterates a tree in pre-order traversal.
 * @tree: The pointer to the root node of the tree to traverse.
 * @flag: balance factor
 * Return: flag
 */
int i_binary_tree_preorder(const binary_tree_t *tree, int flag)
{
	int balance, flag1, flag2;

	if (!tree)
		return (flag);
	balance = i_binary_tree_balance(tree);
	if (balance < 0)
	{
		flag = -1;
		return (-1);
	}
	flag += balance;
	flag1 = i_binary_tree_preorder(tree->left, flag);
	flag2 = i_binary_tree_preorder(tree->right, flag);
	if (flag1 > 0 || flag2 > 0)
		return (-1);
	flag += flag1 + flag2;
	printf("(%d) f1 %d | f2 %d | FLAG %d\n", tree->n, flag1, flag2, flag);
	if (flag == -1)
		return (-1);
	if (flag > 1)
		return (2);
	return (flag); /*1 or 0*/
}
/**
 * i_binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: The pointer to the root of the tree.
 * Return: The balance factor of the tree.
 */
int i_binary_tree_balance(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		l_height = 1 + i_this_binary_tree_height(tree->left, tree->left->n);
	if (tree->right)
		r_height = 1 + i_this_binary_tree_height(tree->right, tree->right->n);
	return (l_height - r_height);
}
/**
 * i_recurse - Measures the height of the entire binary tree.
 * @tree: The pointer to the root node of the tree to measure the height.
 * Return: The height of a binary tree.
 */
int i_recurse(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = i_recurse(tree->left) + 1;
	right_height = i_recurse(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * i_this_binary_tree_height - Measures the height of a binary tree.
 * @tree: The pointer to the root node of the tree to measure the height.
 * @rootval: The value of the root head.
 * Return: The height of a binary tree.
 */
int i_this_binary_tree_height(const binary_tree_t *tree, int rootval)
{
	int depth;

	for (depth = 0; tree && tree->n != rootval; tree = tree->parent, depth++)
		;
	return (i_recurse(tree) - 1 - depth);
}
