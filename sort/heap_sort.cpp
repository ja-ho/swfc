//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//#define swap(a, b) {int t; t = a; a = b; b = t;}
//
//template<typename T>
//void sift_up(T *arr, int root, int current)
//{
//	int parent;
//
//	while (current > root) {
//		parent = current / 2;
//		if (arr[parent] >= arr[current]) return;
//		swap(arr[parent], arr[current]);
//		current = parent;
//	}
//}
//
//template<typename T>
//void heapify_top_down(T *arr, int size)
//{
//	int end = 1;
//	while (end < length) {
//		sift_up
//	}
//}
//
//
//template<typename T>
//void heap_sort(T *arr, int size)
//{
//	
//}
//
//
//int main() {
//	int data[5001];
//	int n;
//	cin >> n;
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++) {
//		data[i] = rand();
//	}
//
//
//	return 0;
//}

#include <iostream>
using namespace std;
#define swap(a, b) {int t; t = a; a = b; b = t;}

void heap(int *data, int num)
{
	for (int i = 1; i < num; i++) {
		int child = i;
		while (child > 0) {
			int root = (child - 1) / 2;
			if (data[root] < data[child]) {
				swap(data[root], data[child]);
			}
			child = root;
		}
	}
	return;
}


int main() {
	int num = 9;
	int data[] = { 15, 4, 8, 11, 6, 3, 1, 6, 5 };
	heap(data, num);

	for (int i = num - 1; i >= 0; i--) {
		swap(data[i], data[0]);
		heap(data, i);
	}

	for (int i = 0; i < num; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
	return 0;
}