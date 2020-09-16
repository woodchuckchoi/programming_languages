#include <stdio.h>

int main() {
	int a;
	char b;
	double d;

	printf("%p\n%p\n%p\n", &a, &b, &d);
	printf("%p\n%p\n%p", &a+1, &b+1, &d+1);

	return 0;
}
