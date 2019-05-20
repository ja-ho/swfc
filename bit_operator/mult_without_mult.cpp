#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int mult_result = 0;
	int idx = 0;
	while (b) {
		if (b & 1) {
			mult_result += a << idx;
		}
		b >>= 1;
		idx++;
	}
	printf("%d\n", mult_result);
	return 0;
}