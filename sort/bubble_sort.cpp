#include <iostream>
using namespace std;

#define MAX 5001

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void bubble_sort(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
		cout << "-------step" << i << '\n';
		for (int k = 0; k < size; k++) {
			cout << arr[k] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	int data[MAX];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}

	cout << "-------start" << '\n';
	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';

	bubble_sort(data, n);

	cout << "-------finished" << '\n';
	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';

	return 0;
}