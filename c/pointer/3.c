#include <stdio.h>

int main() {
	int a = 77;
	const int* ptr = &a;
	int** pptr = &ptr;
	printf("%d", **pptr);
	**pptr = 99;
	printf("%d", **pptr);
	return 0;
}
