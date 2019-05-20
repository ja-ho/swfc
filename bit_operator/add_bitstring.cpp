#include <stdio.h>
#include <string.h>

int calc(char *s1, char *s2)
{
	int s1_int = 0;
	int s2_int = 0;
	int s1_length = strlen(s1);
	int s2_length = strlen(s2);
	int idx = 0;
	for (int i = s1_length -1; i >= 0; i--) {
		if (s1[i] == '1') {
			s1_int += (1 << idx);
		}
		idx++;
	}
	idx = 0;
	for (int i = s2_length - 1; i >= 0; i--) {
		if (s2[i] == '1') {
			s2_int += (1 << idx);
		}
		idx++;
	}
	return s1_int + s2_int;
}

int main() {
	char s1[201], s2[201];
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s %s", &s1, &s2);
		int mult_result = calc(s1, s2);
		int idx = 1;
		int length = 0;
		int temp_result = 1;
		while (mult_result > temp_result) {
			temp_result *= 2;
			length++;
		}
		for (int i = length - 1; i >= 0; i--) {
			printf("%d", (mult_result >> i) & 1);
		}
		printf("\n");
	}
	return 0;
}