#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a, b) ((a > b) ? (a) : (b))
#define swap(a, b) {int t; t = a; a = b; b = t;}

void quick_sort(int *arr, int size);

int main() {
	int size;
	int *arr;
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	quick_sort(arr, size);

	printf("---------- after quick sort\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void quick_sort(int *arr, int size)
{
	if (size == 1) return;	//1���� ����
	int mid = size / 2;		//mid
	int pivot = 0;
	if (size == 2) pivot = 0;	//size�� 2�� �׳� left�� pivot����
	else {
		if (arr[0] > arr[size - 1]) {
			if (arr[0] > arr[mid]) {
				if (arr[mid] > arr[size - 1]) {
					pivot = mid;
				}
				else pivot = size - 1;
			}
			else pivot = 0;
		}
		else {
			if (arr[size - 1] > arr[mid]) {
				if (arr[mid] > arr[0]) {
					pivot = mid;
				}
				else pivot = 0;
			}
			else pivot = size - 1;
		}
	}		//pivot�� left, right, mid �� �߰������� ����. �־��� ��� ���ϱ�
	
	swap(arr[pivot], arr[0]);			//left ��ġ�� �̿��ϱ� ���� pivot���� left swap
	pivot = arr[0];						//pivot�� pivot index ������
	int left = 0;
	int right = size - 1;
	while (left < right) {
		while (arr[right] >= pivot && left < right) right--;	//pivot���� ���� �� ã�������� right--
		arr[left] = arr[right];									//left ��ġ�� pivot���� ���� �� �־���.
		while (arr[left] <= pivot && left < right) left++;		//pivot���� ū �� ã�������� left++
		arr[right--] = arr[left];								//pivot���� ū ���� right�� �־��ְ� right�� --��ġ���� Ž��
	}
	arr[left] = pivot;											//ã�� ��ġ�� pivot �־���					
	pivot = left;												//pivot�� index��
	if (0 < pivot) quick_sort(arr, pivot);						//pivot���� ���� �� �ٽ� quick_sort
	if (pivot < size - 1) quick_sort(arr + pivot + 1, size - 1 - pivot); //pivot���� ū �� �ٽ� quick_sort
	return;
}
