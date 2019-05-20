#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	int temp = 0;
	temp += (x << 1);
	temp += x;
	temp += (x >> 1);
	printf("%d\n", temp);
	return 0;
}