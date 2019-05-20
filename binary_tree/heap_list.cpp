#include <cstdio>
#include <cstdlib>

typedef struct _node
{
	int data;
	char name[6];
	_node *left;
	_node *right;
} node;

typedef struct _heap
{
	node *root;
	int size;
} heap;

void init_heap(heap *ptr)
{
	ptr->size = 0;
	ptr->root = (node *)malloc(sizeof(node));
	ptr->root->left = NULL;
	ptr->root->right = NULL;
}

void insert_

int main() {
	heap h;


}