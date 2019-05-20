#include <stdio.h>


int main() {
	int a;
	scanf("%d %d", &a);
	int min = a + 1;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			if (min < a + a / i) min = a + a / i;
		}
	}
	printf("%d\n", min);

	return 0;
}