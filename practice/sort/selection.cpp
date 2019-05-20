#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {int t; t = a; a = b; b = t;}

void selection_sort(int *arr, int size);

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
	selection_sort(arr, size);

	printf("-------------after selection sort\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}

void selection_sort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int temp_min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[temp_min] > arr[j]) {
				temp_min = j;
			}
		}
		swap(arr[temp_min], arr[i]);
	}
	return;
}