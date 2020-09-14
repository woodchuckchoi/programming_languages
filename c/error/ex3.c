#include <stdio.h>
#include <stdlib.h>

int main() {
	int dividend	= 20;
	int divisor	= 5;
	int quotient;

	if (divisor == 0) {
		fprintf(stderr, "Division by zero!\n");
		exit(EXIT_FAILURE);
	}
	
	quotient	= dividend / divisor;
	fprintf(stdout, "%d\n", quotient);

	exit(EXIT_SUCCESS);
}
