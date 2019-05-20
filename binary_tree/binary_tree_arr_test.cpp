#include <cstdio>
#include <cstdlib>

#define swap(a, b) {int t; t = a; a = b; b = t;}

int main() {
	int n;
	scanf("%d", &n);
	int *heap = (int *)malloc(sizeof(int) * (n + 1));

	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d", &m);
		heap[i] = m;
		for (int child = i; child > 1; child /= 2) {
			if (heap[child / 2] < heap[child]) {
				swap(heap[child / 2], heap[child]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		swap(heap[1], heap[n - i + 1]);
		int parent = 1;
		while (parent){
			int child = parent * 2;

			if (child > n - i) break;
			if (child + 1 <= n - i && heap[child] < heap[child + 1]) child++;
			
			if (heap[child] > heap[parent]) {
				swap(heap[child], heap[parent]);
			}
			else break;
			parent = child;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ,", heap[i]);
	}
	printf("\n");

	free(heap);
	return 0;
}