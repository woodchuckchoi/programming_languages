#include <stdio.h>
#include "func.h" // static function can only be called from the source code where it was defined

int main() {
	test();
	test2();
	return 0;
}

void test() {
	printf("not static\n");
}
