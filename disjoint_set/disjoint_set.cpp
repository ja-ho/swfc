#include <iostream>
using namespace std;

int find(int x, int *arr)
{
	if (x == arr[x]) {
		return x;
	}
	else {
		return arr[x] = find(arr[x], arr);
	}
}

void union_func(int x, int y, int *arr)
{
	x = find(x, arr);
	y = find(y, arr);
	arr[y] = x;
}



int main() {
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");

	union_func(1, 2, arr);
	printf("------------\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	union_func(4, 5, arr);
	printf("------------\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	union_func(2, 5, arr);
	printf("------------\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	delete []arr;
	return 0;
}