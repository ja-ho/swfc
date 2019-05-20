#include <stdio.h>

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	int mask = 1;
	int cnt = 0;
	
	n &= (d - 1);
	printf("%d\n", n);
	return 0;
}