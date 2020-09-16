#include <stdio.h>

int main() {
	int arr[5] = {1,2,3,4,5};
	int* ptr = arr;

	printf("size of arr: %ld", sizeof(arr));
	printf("size of ptr: %ld", sizeof(ptr));

	return 0;
}
