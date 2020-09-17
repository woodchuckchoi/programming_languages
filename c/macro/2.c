#include <stdio.h>
#define NAMECONCAT(a, b) a##b
#define PRINTVAR(var) printf(#var);

int main() {
	int NAMECONCAT(a, b);
	ab = 3;

	PRINTVAR(ab);
	printf(" = %d\n", ab);

	return 0;
}
