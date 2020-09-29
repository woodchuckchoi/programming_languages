#include <stdio.h>

struct test {
	int a;
	int b;
};

int main() {
	struct test test[10];
	test[0].a = 5;
	test[0].b = 10;
	printf("%d\n", test[0].a);
	return 0;
}
