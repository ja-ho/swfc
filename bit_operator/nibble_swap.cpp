#include <cstdio>

unsigned char nibble_swap(unsigned char x)
{
	return (((x & 0xF0) >> 4) | ((x & 0x0F) << 4));
}

int main() {
	unsigned char x = 100;
	x = nibble_swap(x);
	printf("%u\n", x);
	return 0;
}