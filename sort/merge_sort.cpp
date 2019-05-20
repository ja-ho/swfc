#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
void merge_sort(T *arr, int size)
{
	if (size <= 1) return;
	int i, j, k;
	T temp;
	//if (size < 16) {		//size가 적으면 insertion으로
	//	for (i = 1; i < size; i++) {
	//		temp = arr[i];
	//		for (j = i - 1; j >= 0; j--) {
	//			if (temp >= arr[j]) break;
	//			arr[j + 1] = arr[j];
	//		}
	//		arr[j + 1] = temp;
	//	}
	//	return;
	//}
	int half = size / 2;
	merge_sort(arr, half);
	merge_sort(arr + half, size - half);

	T *s = new T[size];

	for (i = 0, j = half, k = 0; i < half && j < size; ) {
		s[k++] = (arr[i] >= arr[j] ? arr[j++] : arr[i++]);
	}

	while (i < half) s[k++] = arr[i++];
	while (j < size) s[k++] = arr[j++];

	for (i = 0; i < size; i++) {
		arr[i] = s[i];
	}
	delete[] s;
}


int main() {
	int data[5001];
	int n;
	cin >> n;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		data[i] = rand();
	}
	merge_sort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
	return 0;
}



merge sort (int *arr, int size){
	if (size <= 1) return;
	int i, j, k;
	int half = size / 2;
	merge sort(arr, half);
	merge sort(arr + half, size - half);

	int *s = new int[size];
	for (i = 0, j = half, k = 0; i < half && j < size;) {
		s[k++] = (arr[i] > arr[j] ? arr[j++] : arr[i++]);
	}

	while (i < half) s[k++] = arr[i++];
	while (j < size) s[k++] = arr[j++];

	for (int i = 0; i < size; i++) {
		arr[i] = s[i];
	}
	delete[] s;
}