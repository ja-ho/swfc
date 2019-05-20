#include <cstdio>
#include "my_queue.h"

int main() {
	create_queue(5);
	for (int i = 0; i < 5; i++) {
		push(i);
		printf("%d: %d\n", i + 1, get_front());
	}
	printf("-----------\n");
	for (int i = 0; i < 5; i++) {
		printf("%d: %d\n", i + 1, get_front());
		pop();
	}

	if (is_empty()) {
		printf("yes!\n");
	}

	for (int i = 7; i >= 0; i--) {
		push(i);
	}

	printf("-----------\n");
	while (!is_empty()) {
		printf("%d\n", get_front());
		pop();
	}
	
	return 0;
}