#include <iostream>
using namespace std;

#define MAX 5000

void insertion_sort(int *arr, int size)
{
	int i, j;
	for (i = 1; i < size; i++) {
		int temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < temp) break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
		cout << "-----step" << i << '\n';
		for (int k = 0; k < size; k++) {
			cout << arr[k] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	int data[MAX];
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> data[i];
	}
	cout << "-----start" << '\n';
	for (int i = 0; i < size; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';

	insertion_sort(data, size);

	cout << "-----finished" << '\n';
	for (int i = 0; i < size; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';


	return 0;
}
