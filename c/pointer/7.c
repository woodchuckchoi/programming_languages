#include <stdio.h>

int main() {
	int arr[2][2][2] = {{{1,2}, {3,4}}, {{5, 6}, {7, 8}}};
	int (*ptr)[2][2] = arr;
	int **pptr = arr; // Error
	printf("ptr: %p\narr: %p\n", ptr, arr);
	printf("ptr[1][1][1]: %d\narr[1][1][1]: %d\n", ptr[1][1][1], arr[1][1][1]);

	return 0;
}
