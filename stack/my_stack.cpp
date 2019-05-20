#include "my_stack.h"
#include <cstdio>
#include <cstdlib>

int top = -1;
int stack_size;
int *create_stack(int size)
{
	if (size > MAX_SIZE) {
		printf("MAX_SIZE is 5000\n");
		return nullptr;
	}
	int *p = (int *)malloc(sizeof(int) * size);	
	stack_size = size;
	return p;
}

int get_top(int *p)
{
	return p[top];
}
void push(int *p, int n)
{
	top++;
	if (is_full(p)) {
		printf("this stack is full\n");
		top--;
		return;
	}
	p[top] = n;
}
void pop(int *p)
{
	if (is_empty(p)) {
		printf("this stack is empty\n");
		return;
	}
	top--;
}
void expand_stack(int *p)
{
	if (stack_size * 2 > MAX_SIZE) {
		printf("stack size is too large\n");
	}
	realloc(p, stack_size * 2 * sizeof(int));
}

bool is_full(int *p)
{
	return (top >= stack_size);
}
bool is_empty(int *p)
{
	return (top < 0);
}