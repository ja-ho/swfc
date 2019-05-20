#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "my_stack.h"
int main() {
	int *st_p;
	st_p = create_stack(5);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 7; i++) {
		push(st_p, rand());
	}
	while (!is_empty(st_p)) {
		printf("%d\n", get_top(st_p));
		pop(st_p);
	}
	if (is_empty(st_p)) {
		printf("now stack is empty\n");
	}

	return 0;
}