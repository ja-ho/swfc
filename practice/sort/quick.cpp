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
	if (size == 1) return;	//1개면 리턴
	int mid = size / 2;		//mid
	int pivot = 0;
	if (size == 2) pivot = 0;	//size가 2면 그냥 left를 pivot으로
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
	}		//pivot을 left, right, mid 중 중간값으로 설정. 최악의 경우 피하기
	
	swap(arr[pivot], arr[0]);			//left 위치를 이용하기 위해 pivot값과 left swap
	pivot = arr[0];						//pivot을 pivot index 값으로
	int left = 0;
	int right = size - 1;
	while (left < right) {
		while (arr[right] >= pivot && left < right) right--;	//pivot보다 작은 값 찾을때까지 right--
		arr[left] = arr[right];									//left 위치에 pivot보다 작은 값 넣어줌.
		while (arr[left] <= pivot && left < right) left++;		//pivot보다 큰 값 찾을때까지 left++
		arr[right--] = arr[left];								//pivot보다 큰 값을 right에 넣어주고 right는 --위치부터 탐색
	}
	arr[left] = pivot;											//찾은 위치에 pivot 넣어줌					
	pivot = left;												//pivot에 index값
	if (0 < pivot) quick_sort(arr, pivot);						//pivot보다 작은 곳 다시 quick_sort
	if (pivot < size - 1) quick_sort(arr + pivot + 1, size - 1 - pivot); //pivot보다 큰 곳 다시 quick_sort
	return;
}
