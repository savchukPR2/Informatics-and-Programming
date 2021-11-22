#include <stdio.h>

int main() {
	int n = 4;

	int* p = &n;
	*p = 5;
	printf("%d", n);

	printf("%d\n", &n == 5);

	int** pp = &p;
	*(int*)p = 6;
	printf("%d", n);

	int*** ppp = &pp;
	*(int*)(int*)p = 7;
	printf("%d\n", n);

	int mass[3];
	*(mass + 0) = *p;
	*(mass + 2) = 1;
	for (int i = 0; i < 3; i++) {
		printf("%d ", *(mass + i));
	}

	getchar();
	return 0;
}