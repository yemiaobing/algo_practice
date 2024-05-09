#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int recur_fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return recur_fib(n - 2) + recur_fib(n - 1);
}

int __tail_recur_fib(int n, int a, int b)
{
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	return __tail_recur_fib(n - 1, b, a + b);
}

int tail_recur_fib(int n)
{
	return __tail_recur_fib(n, 0, 1);
}

int iter_fib(int n)
{
	int a = 0;
	int b = 1;
	int i = 0;
	int fib = 0;

	if (n == 0)
		return a;
	if (n == 1)
		return b;

	for (i = 2; i <= n; i++) {
		fib = a + b;
		a = b;
		b = fib;
	}

	return fib;
}

int main(void)
{
	int i = 0;

	printf("斐波那契数列前 20 个数字\n");
	printf("循环\t");
	for (i = 0; i < 20; i++) {
		printf("%d ", iter_fib(i));
	}
	printf("\n");
	printf("递归\t");
	for (i = 0; i < 20; i++) {
		printf("%d ", recur_fib(i));
	}
	printf("\n");
	printf("尾递归\t");
	for (i = 0; i < 20; i++) {
		printf("%d ", tail_recur_fib(i));
	}
	printf("\n");

	return 0;
}
