#include <stdio.h>

struct test {
	int a;
	int b;
};

void tester(struct test test) {
	test.a = 10;
}

int main() {
	struct test test;
	test.a = 5;
	test.b = 10;
	tester(test);
	printf("%d\n", test.a);
	return 0;
}
