#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {int t; t = a; a = b; b = t;}

void shell_sort(int *arr, int size);
void gap_insertion_sort(int *arr, int gap, int size);

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
	shell_sort(arr, size);

	printf("-------------after shell sort\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}

void shell_sort(int *arr, int size)
{
	for (int i = size / 2; i >= 1; i /= 2) {
		gap_insertion_sort(arr, i, size);
	}
	return;
}

void gap_insertion_sort(int *arr, int gap, int size)
{
	int i, j, k;
	for (i = 0; i < gap; i++) {
		for (k = i + gap; k < size; k += gap) {
			int temp = arr[k];
			for (j = k; j >= 0; j -= gap) {
				if (j - gap < 0) break;
				if (arr[j - gap] < temp) break;
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	return;
}