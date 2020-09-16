#include <stdio.h>

struct Test {
	int i;
	char *s;
};

int main() {
	struct Test Test;

	Test.i = 30;
	Test.s = "HHOHO";

	struct Test *ptest = &Test;

	ptest->i = 31;
	ptest->s = "OIOI";

	printf("%d %s", Test.i, Test.s);
	printf("\n%p %p", &Test.i, &Test.s);
	printf("\n%p\n", "something");
	return 0;
}
