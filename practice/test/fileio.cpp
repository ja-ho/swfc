#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp = fopen("test.txt", "w");
	if (fp == NULL) {
		puts("can't open the file");
		exit(0);
	}
	else {
		//fputs("hey, ho", fp);
		fprintf(fp, "hey, ho");
		puts("done");
		fclose(fp);
	}
	return 0;
}