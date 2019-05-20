#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int mask = 1;
	while (mask <= n) {
		if (mask == n) {
			printf("%d\n", 1);
			return 0;
		}
		mask <<= 2;
	}
	printf("%d\n", 0);

	return 0;
}