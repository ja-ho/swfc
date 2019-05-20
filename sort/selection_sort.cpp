#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}

void selection_sort(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
		int temp_j = i;
		for (int j = i; j < size; j++) {
			if (arr[temp_j] > arr[j]) {
				temp_j = j;
			}
		}	
		
		swap(arr[i], arr[temp_j]);
		cout << "======step" << i << '\n';
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	return;
}


int main() {
	int data[] = { 1000, 5, 8, 100, 3, 8, 2 , 9, 11, 22, 14};
	cout << "------start" << '\n';
	for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';

	selection_sort(data, sizeof(data) / sizeof(int));

	cout << "------finished" << '\n';
	for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
	return 0;
}