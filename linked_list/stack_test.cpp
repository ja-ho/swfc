#include <cstdio>
#include <cstdlib>
#include "my_linked_list.h"
#include "stack_linked_list.h"

int main() {
	char command[10];
	stack stack_ptr;
	int n;
	scanf("%d", &n);

	init_stack(&stack_ptr);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%s", &command);
		if (command[0] == 's') {
			printf("%d\n", stack_size(&stack_ptr));
		}
		else if (command[0] == 't') {
			printf("%d\n", get_top(&stack_ptr));
		}
		else if (command[1] == 'u') {
			scanf("%d", &temp);
			push(&stack_ptr, temp);
		}
		else if (command[1] == 'o') {
			pop(&stack_ptr);
		}
	}
	return 0;
}