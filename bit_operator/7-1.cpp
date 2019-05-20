#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, d;
		scanf("%d %d", &n, &d);
		d %= 16;
		int mask = (1 << 16) - 1;
		printf("%d\n", ((mask & (n >> (16 - d))) | (mask & (n << d))));
		printf("%d\n", ((mask & (n >> d))) | mask & (n << (16 - d)));
	}
	return 0;
}