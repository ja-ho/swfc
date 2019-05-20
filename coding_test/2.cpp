#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 25

int matrix[MAX][MAX];
int arr[MAX + 1];

int main() {
	int row, col;
	scanf("%d %d", &row, &col);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = rand() % MAX;
		}
	}
	
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if()
		}
	}


	return 0;
}