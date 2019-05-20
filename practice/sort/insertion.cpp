#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {int t; t = a; a = b; b = t;}

void insertion_sort(int *arr, int size);

int main() {
	int size;
	int *arr;
	srand((unsigned int)time(NULL));
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	insertion_sort(arr, size);

	printf("-------------after insertion sort\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}

void insertion_sort(int *arr, int size)
{
	int i, j;
	for (i = 1; i < size; i++) {
		int temp = arr[i];
		for (j = i; j >= 1; j--) {
			if (temp >= arr[j - 1]) break;
			else {
				arr[j] = arr[j - 1];
			}
		}
		arr[j] = temp;
	}
	return;
}