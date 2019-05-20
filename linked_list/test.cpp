#include <cstdio>
#include <cstdlib>
#include "my_linked_list.h"

int main() {
	char command[10];
	list list_ptr;
	int n;
	scanf("%d", &n);

	init_list(&list_ptr);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%s", &command);
		if (command[0] == 's') {
			printf("%d\n", get_size(&list_ptr));
		}
		else if (command[0] == 'p') {
			scanf("%d", &temp);
			push_back(&list_ptr, temp);
		}
		else if (command[0] == 'g') {
			scanf("%d", &temp);
			int idx_x = get_idx(&list_ptr, temp);
			if (idx_x == -1) {
				printf("cannot found the number\n");
			}
			else {
				printf("%d\n", idx_x);
			}
		}
		else if (command[1] == 'o') {
			scanf("%d", &temp);
			printf("%d\n", count_target(&list_ptr, temp));
		}
		else if (command[1] == 'l') {
			list_clear(&list_ptr);
		}
	}
	return 0;
}