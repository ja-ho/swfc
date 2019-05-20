#include <stdio.h>

void push(int *stack, int *top, int value)
{
	if (*top > 100) return;
	stack[(*top)++] = value;
	return;
}

int pop(int *stack, int *top)
{
	if (*top < 0) return -1;
	return stack[--(*top)];
}

int get_top(int *stack, int *top)
{
	if (*top < 0) return -1;
	return stack[*top - 1];
}

int main() {
	int stack[100];
	int st_top = 0;
	for (int i = 0; i < 10; i++) {
		push(stack, &st_top, i * 2);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", get_top(stack, &st_top));
	}

	return 0;
}