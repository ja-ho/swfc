#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int t; t = a; a = b; b = t;}

void bubble_sort(int *arr, int size);

int main() {
	int size;
	int *arr;
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, size);
	printf("--------------after sort\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void bubble_sort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
	return;
}
