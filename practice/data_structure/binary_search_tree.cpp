#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_node {
	int value;
	_tree_node *left;
	_tree_node *right;
} tree_node;

typedef struct _tree {
	tree_node *root;
	int size;
	tree_node *ptr;
} tree;

void add(tree_node *root, tree_node *temp)
{
	if (root == NULL) return;
	if (root->value > temp->value) {
		if (root->left) {
			add(root->left, temp);
		}
		else {
			root->left = temp;
		}
	}
	else {
		if (root->right) {
			add(root->right, temp);
		}
		else {
			root->right = temp;
		}
	}
	return;
}

void insert(tree *tree, int value)
{
	tree_node *temp = (tree_node *)malloc(sizeof(tree_node));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	tree->size++;
	if (tree->root == NULL) {
		tree->root = temp;
	}
	else {
		add(tree->root, temp);
	}
	return;
}

int find(tree_node *root, int value)
{
	if (root == NULL) return -1;
	else if (root->right && root->value < value) {
		return find(root->right, value);
	}
	else if (root->left && root->value > value) {
		return find(root->left, value);
	}
	else {
		return root->value;
	}
	return -1;
}

int search(tree *tree, int value)
{
	if (tree->root == NULL) return -1;
	return find(tree->root, value);
}

void inorder_traversal(tree_node *root)
{
	if (root == NULL) return;
	inorder_traversal(root->left);
	printf("%d ", root->value);
	inorder_traversal(root->right);
	return;
}

void free_bst(tree_node *root)
{
	if (root == NULL) return;
	free_bst(root->left);
	free_bst(root->right);
	free(root);
	return;
}


int main() {
	tree root;
	root.root = NULL;
	root.size = 0;
	root.ptr = NULL;

	for (int i = 0; i < 10; i++) {
		insert(&root, i);
	}
	inorder_traversal(root.root);

	printf("find 5 : %d\n", search(&root, 5));
	free_bst(root.root);
	return 0;
}