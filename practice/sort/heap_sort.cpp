//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define max(a, b) ((a > b) ? (a) : (b))
//#define swap(a, b) {int t; t = a; a = b; b = t;}
//
//void heap_sort(int *arr, int size);
//void heapify(int *arr, int index, int size);
//void insert_heap(int *arr, int *size, int value);
//int delete_heap(int *arr, int *size);
//
//int main() {
//	int size;
//	int *arr;
//	scanf("%d", &size);
//	arr = (int *)malloc(sizeof(int) * (size + 1));
//	int heap_size = 0;
//	srand((unsigned int)time(NULL));
//	for (int i = 1; i <= size; i++) {
//		insert_heap(arr, &heap_size, rand() % 1000);
//	}
//
//	for (int i = 1; i <= size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	//heap_sort(arr, size);
//
//	printf("---------- after heap sort\n");
//	for (int i = 1; i <= size; i++) {
//		printf("%d ", delete_heap(arr, &heap_size));
//	}
//	printf("\n");
//	return 0;
//}
//
//void heap_sort(int *arr, int size)
//{
//	
//}
//
////void heapify(int *arr, int index, int size)
////{
////	while (index < size) {
////		int child = index * 2;
////		if (child > size) break;
////		if (child + 1 <= size && arr[child + 1] > arr[child]) child++;
////		if (arr[child] > arr[index]) swap(arr[index], arr[child]);
////		index *= 2;
////	}
////	return;
////}
//
//void heapify(int *arr, int index, int size)
//{
//	int largest = index;
//	int l = 2 * index;
//	int r = 2 * index + 1;
//
//	//if l is the largest
//	if (l <= size && arr[l] > arr[largest]) largest = l;
//	//if r is the largest
//	if (r <= size && arr[r] > arr[largest]) largest = r;
//	//if target is not root
//	if (index != largest) {
//		swap(arr[index], arr[largest]);
//		heapify(arr, largest, size);
//	}
//	return;
//}
//
//void insert_heap(int *arr, int *size, int value)
//{
//	int i = (*size)++ + 1;
//	while (i != 1 && value > arr[i / 2]) {
//		arr[i] = arr[i / 2];
//		i /= 2;
//	}
//	arr[i] = value;
//	return;
//}
//
//int delete_heap(int *arr, int *size)
//{
//	int delete_node = arr[1];
//	arr[1] = arr[(*size)-- -1];
//	heapify(arr, 1, *size);
//	return delete_node;
//}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap(a, b) {int t; t = a; a = b; b = t;}

int main() {
	int data[10];
	int size = 10;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		data[i] = rand() % 1000;
	}

	for (int i = 0; i < size; i++) {
		for (int child = i; child >= 1; child = (child - 1) / 2) {
			int root = (child - 1) / 2;
			if (data[root] < data[child]) {
				swap(data[root], data[child]);
			}
			else break;
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		swap(data[0], data[size - 1 - i]);
		int child = 1;
		int root = 0;
		while (child < size - 1 - i) {
			if (child + 1 < size - 1 - i && data[child] < data[child + 1]) child++;
			if (data[child] > data[root]) {
				swap(data[child], data[root]);
			}
			else break;
			root = child;
			child = root * 2 + 1;
		}
	}

	for(int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
