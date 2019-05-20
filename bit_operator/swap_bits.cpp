#include<stdio.h>

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
	/* Move all bits of first set to rightmost side */
	unsigned int set1 = (x >> p1) & ((0x1 << n) - 1);

	/* Move all bits of second set to rightmost side */
	unsigned int set2 = (x >> p2) & ((0x1 << n) - 1);

	/* XOR the two sets */
	unsigned int xor = (set1 ^ set2);

	/* Put the xor bits back to their original positions */
	xor = (xor << p1) | (xor << p2);

	/* XOR the 'xor' with the original number so that the
	two sets are swapped */
	unsigned int result = x ^ xor;

	return result;
}

/* Driver program to test above function*/
int main()
{
	int res = swapBits(28, 0, 3, 2);
	printf("\nResult = %d ", res);
	return 0;
}