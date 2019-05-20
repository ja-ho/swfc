#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	string str;
	int test;
	cin >> test;
	int *result = (int *)malloc(sizeof(int) * test + 1);
	int idx = 0;
	for (int i = 0; i < test; i++) {
		result[i] = -2;
	}
	while (test--) {
		cin >> str;
		int len = str.size();
		int check = 1;
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - i - 1]) {
				check = 0;
				break;
			}
		}
		if (check == 1) result[idx++] = -1;
		else {
			int c2 = 1;
			for (int i = 0; i < len; i++) {
				int head = 0;
				int tail = len - 1;
				while (head < tail) {
					c2 = 1;
					if (head == i) head++;
					if (tail == i) tail--;
					if (str[head++] != str[tail--]) {
						c2 = 0;
						break;
					}
				}
				if (c2 == 1) {
					result[idx++] = i;
					break;
				}
			}
		}
		printf("");
	}

	free(result);
	return 0;
}