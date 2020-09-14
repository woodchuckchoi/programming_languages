#include <stdio.h>

int main() {

	int n[10];
	int i, j;

	for (i = 0; i < 10; i++) {
		n[i] = i + 100;
	}

	for (i = 0; i < sizeof(n)/sizeof(n[0]); i++) {
		printf("Element[%d] = %d\n", i, n[i]);
	}

	return 0;
}
