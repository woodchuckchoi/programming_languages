#include <stdio.h>
#include <stdlib.h>

int main() {
	int dividened	= 20;
	int divisor	= 0;
	int quotient;

	if (divisor == 0) {
		fprintf(stderr, "Dvision by zero!\n");
		exit(-1);
	}

	quotient	= dividened / divisor;
	fprintf(stderr, "%d\n", quotient);

	exit(0);
}
