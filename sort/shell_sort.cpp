#include <iostream>
using namespace std;

#define MAX 5001

void shell_sort(int *arr, int size);

int main() {
	int data[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	shell_sort(data, n);

	cout << "------finished" << '\n';
	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
	return 0;
}

void shell_sort(int *arr, int size)
{
	int step, i, j, m;
	for (step = size / 2; step >= 1; step /= 2) {
		for (m = 0; m < step; m++) {
			for (i = m + step; i < size; i += step) {
				int temp = arr[i];
				for (j = i - step; j >= 0; j -= step) {
					if (arr[j] <= temp) break;
					arr[j + step] = arr[j];
				}
				arr[j + step] = temp;
				cout << "------step" << step << '\n';
				for (int k = 0; k < size; k++) {
					cout << arr[k] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return;
}

