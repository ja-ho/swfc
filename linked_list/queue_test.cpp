#include <cstdio>
#include <cstdlib>
#include "my_linked_list.h"
#include "queue_linked_list.h"

int main() {
	char command[10];
	queue q_ptr;
	int n;
	scanf("%d", &n);

	init_queue(&q_ptr);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%s", &command);
		if (command[0] == 's') {
			printf("%d\n", queue_size(&q_ptr));
		}
		else if (command[0] == 'e') {
			scanf("%d", &temp);
			enqueue(&q_ptr, temp);
		}
		else if (command[0] == 'd') {
			dequeue(&q_ptr);
		}
		else if (command[0] == 'f') {
			printf("%d\n", get_front(&q_ptr));
		}
	}
	return 0;
}