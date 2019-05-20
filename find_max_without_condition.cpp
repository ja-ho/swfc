#include <cstdio>


int main() {
	int arr[3][3] = { 12,3,4,5,6,7,8,9,0 };
	int(*p)[3] = arr;

	int *parr[3];
	int **pp = parr;
	return 0;
}