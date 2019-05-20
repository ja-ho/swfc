#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {int t; t = a; a = b; b = t;}

void merge_sort(int *arr, int size);

int main() {
	int size;
	int *arr;
	srand((unsigned int)time(NULL));
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	merge_sort(arr, size);

	printf("-------------after shell sort\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}

void merge_sort(int *arr, int size)
{
	if (size == 1) return;
	merge_sort(arr, size / 2);
	merge_sort(arr + size / 2, size - size /2);

	int *temp_arr = (int *)malloc(sizeof(int) * size);
	int i = 0; 
	int j = size / 2;
	int idx = 0;
	while (i < size / 2 && j < size) {
		if (arr[i] < arr[j]) temp_arr[idx++] = arr[i++];
		else temp_arr[idx++] = arr[j++];
	}
	while (i < size / 2) temp_arr[idx++] = arr[i++];
	while (j < size) temp_arr[idx++] = arr[j++];

	for (idx = 0; idx < size; idx++) {
		arr[idx] = temp_arr[idx];
	}
	free(temp_arr);
	return;
}
