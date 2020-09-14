#include <stdio.h>

struct Age {
	unsigned int tmp: 3;
};

int main() {
	struct Age test;
	
	test.tmp = 4;
	printf("%d\n", test.tmp);

	test.tmp = 7;
	printf("%d\n", test.tmp);
	
	test.tmp = 9;
	printf("%d\n", test.tmp);

	return 0;

}
