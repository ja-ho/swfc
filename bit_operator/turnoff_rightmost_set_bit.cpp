#include <stdio.h>
//int main() {
//	int n;
//	scanf("%d", &n);
//
//	int mask = 1;
//	int cnt = 0;
//	while (!(mask & n)) {
//		mask <<= 1;
//	}
//
//	n = (n ^ mask);
//
//	printf("%d\n", n);
//	return 0;
//}

int main() {
	int n;
	scanf("%d", &n);
	n = (n & (n - 1));
	printf("%d\n", n);
	return 0;
}