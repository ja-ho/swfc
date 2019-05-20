#include <stdio.h>

int arr[501];

int find_alone(int n)
{
	int alone = 0;
	for (int i = 0; i < n; i++) {
		alone ^= arr[i];
	}
	return alone;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int alone = find_alone(n);
		printf("%d\n", alone);
	}
	return 0;
}