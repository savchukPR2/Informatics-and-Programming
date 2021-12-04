#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

#define RECURS 1
#define BASE 2

#include <stdio.h>
#include <math.h>

int div = 0;
int num;

simple_num(n, div) {

	printf("recursion method: \n");

	if (div == 0)
		div = n - 1;
	while (div >= 2) {
		if (n % div == 0) {
			printf("Number is not simple\n");
			return false;
		}
		else
			return simple_num(n, div - 1);
	}

	return printf("Number is simple");
}

int user_choose() {

	while (true) {

		printf("Choose your metod: \n 1 - Recursion method \n 2 - Simple method \n");
		scanf_s("%d\n", &num);
		if (num >= RECURS && (num <= BASE))
			return num;

	}

}

int simple_method(int num) {

	printf("Simple method: \n");

	int sum = 0;

	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			sum++;
		}
	}

	if (sum == 2)
		printf("The number is simple");
	else
		printf("The number is not simple");
}

int main() {

	switch (user_choose())
	{
	case RECURS:
		simple_num(num, div);
		break;
	case BASE:
		simple_method(num);
		break;
	}
}