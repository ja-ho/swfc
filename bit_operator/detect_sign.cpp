#include <stdio.h>

bool detect_sign(int a, int b)
{
	return ((a ^ b) < 0);
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (detect_sign(x, y)) {
		printf("it is opposite sign\n");
	}
	else {
		printf("it is not opposite sign\n");
	}
	return 0;
}