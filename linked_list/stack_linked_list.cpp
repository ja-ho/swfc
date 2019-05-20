#include "stack_linked_list.h"
#include "my_linked_list.h"
#include <cstdio>
#include <cstdlib>

void init_stack(stack *stack_ptr)
{
	stack_ptr->size = 0;
	stack_ptr->top = NULL;
}

int get_top(stack *stack_ptr)
{
	return stack_ptr->top->data;
}

int stack_size(stack *stack_ptr)
{
	return stack_ptr->size;
}

void push(stack *ptr, int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = ptr->top;
	ptr->top = temp;
	ptr->size++;
	return;
}

void pop(stack *ptr)
{
	node *temp = ptr->top;
	ptr->top = ptr->top->next;
	free(temp);
	ptr->size--;
	return;
}

bool is_empty(stack *ptr)
{
	return !(ptr->size);
}
