#include <stdio.h>

int main() {
	double d;
	double *ptrd = &d;
	void *ptrv = (void *)ptrd;

	printf("ptrd: %p\nptrv: %p\n", ptrd, ptrv); 

	int arr[] = {1,2,3};
	int *parr = arr;
	void *varr = parr;

	printf("arr[2] in parr: %d\narr[2] in varr: %d\n", *(parr+2), *(varr+2));
	// Error since the compiler doesn't know how much memory it should read from varr + 2

	return 0;
}
