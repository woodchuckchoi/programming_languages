#include <stdio.h>

int fibonacci(int i) {
	if (i <= 1) {
		return i;
	}
	return fibonacci(i-1) + fibonacci(i-2);
}

int main() {
	int i;

	for (i = 0; i < 10; i++) {
		fprintf(stdout, "%d\n", fibonacci(i));
	}

	return 0;
}
