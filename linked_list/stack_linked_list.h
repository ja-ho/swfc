#pragma once
#include "my_linked_list.h"
#define MAX_SIZE 5000

typedef struct _stack
{
	node *top;
	int size;
} stack;

void init_stack(stack *stack_ptr);
int get_top(stack *ptr);
void push(stack *ptr, int value);
void pop(stack *ptr);
bool is_empty(stack *ptr);
int stack_size(stack *stack_ptr);

