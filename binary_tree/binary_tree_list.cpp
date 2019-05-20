#include <cstdio>
#include <cstdlib>

typedef struct _node
{
	int data;
	char name[6];
	_node *left;
	_node *right;
} node;

typedef struct _tree{
	node *root;
	int size;
} tree;

void init_tree(tree *ptr)
{
	ptr->size = 0;
	ptr->root = (node *)malloc(sizeof(node));
	ptr->root->left = NULL;
	ptr->root->right = NULL;
}

node *insert(node *root, node *temp)
{
	if (root == NULL) return temp;
	if (root->data > temp->data) {
		root->left = insert(root->left, temp);
		return root->left;
	}
	else {
		root->right = insert(root->right, temp);
		return root->right;
	}
}

void add(tree *tree_ptr, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->left = nullptr;
	temp->right = nullptr;
	if (tree_ptr->size == 0) {
		tree_ptr->root = temp;
	}
	else {
		insert(tree_ptr->root, temp);
	}
	tree_ptr->size++;
	return;
}

node *get(node *_node, node *target)
{
	if (_node == NULL) return;
	if (_node->data > target->data) {
		return get(_node->left, target);
	}
	else if (_node->data < target->data) {
		return get(_node->right, target);
	}
	else return target;
}

node *get_data(tree* ptr, int value)
{
	if (ptr->root == nullptr) return nullptr;
	node *temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->left = nullptr; temp->right = nullptr;
	return get(ptr->root, temp);
}

node *_remove(node* ptr, int target)
{
	node *new_root, *exchange, temp;
	if (ptr == nullptr) return nullptr;
	if (ptr->data > target) {
		ptr->left = _remove(ptr->left, target);
	}
	else if (ptr->data < target) {
		ptr->right = _remove(ptr->right, target);
	}
	else {
		if (!ptr->left) {
			new_root = ptr->right;
			return new_root;
		}
		else if (!ptr->right) {
			new_root = ptr->left;
			return new_root;
		}
		else {
			exchange = ptr->left;
			while (exchange->right) exchange = exchange->right;
			temp.data = ptr->data;
			ptr->data = exchange->data;
			exchange->data = temp.data;
			ptr->left = _remove(ptr->left, exchange->data);
		}
	}
	return ptr;
}

node *remove(tree *ptr, int value)
{
	if (ptr->root == nullptr) return nullptr;



}

int main() {


}