#include <stdio.h>

int count_set_bit(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;

	return ((n & 1) ? 1 : 0) + count_set_bit((n >> 1));
}


int main() {
	int n;
	scanf("%d", &n);
	int result = count_set_bit(n);
	printf("%d\n", result);
	return 0;
}