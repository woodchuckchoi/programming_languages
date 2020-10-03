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

	struct test *oi; // oi points to NULL, oi only holds storage big enough for the address of of a potential struct test variable.
	/*
	oi->a = 8;
	oi->b = 16;
	*/
	printf("%p\n", oi); // shows nill value
	
	return 0;
}
