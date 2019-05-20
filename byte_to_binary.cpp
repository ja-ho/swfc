#include <cstdio>	//printf
#include <cstdlib>  //strtol
#include <cstring>  //strcat

const char *byte_to_binary(int x)
{
	static char b[9];
	b[0] = '\0';

	int z;
	for (z = 128; z > 0; z >>= 1) {
		if (z & x) {
			strcat(b, "1");
		}
		else strcat(b, "0");
	}
	return b;
}


int main() {
	char *temp;
	char *b = "1010";

	printf("%d\n", strtol(b, &temp, 2));
	printf("%s\n", byte_to_binary(10));


	return 0;
}