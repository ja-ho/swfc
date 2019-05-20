//#include <stdio.h>
//
//int addOvf(int* result, int a, int b)
//{
//	long long test;
//	test = (long long)a + b;
//	if (test < (1 << 31) || test > ((1 << 31) - 1)) {
//		return -1;
//	}
//	else {
//		*result = a + b;
//		return 0;
//	}
//}
//
//int main() {
//	int a, b;
//	int result;
//	scanf("%d %d", &a, &b);
//	if (addOvf(&result, a, b)) {
//		printf("overflow\n");
//	}
//	else {
//		printf("now overflow. result is %d\n", a + b);
//	}
//	return 0;
//}
//

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int addOvf(int* result, int a, int b)
{
	if (a > INT_MAX - b)
		return -1;
	else
	{
		*result = a + b;
		return 0;
	}
}

int main()
{
	int *res = (int *)malloc(sizeof(int));
	int x = -2000000000;
	int y = -2000000000;

	printf("%d", addOvf(res, x, y));
	printf("\n %d", *res);
	getchar();
	return 0;
}