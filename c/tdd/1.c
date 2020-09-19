#include <stdio.h>

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do {if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do {int r=test(); tests_run++; if(r) return r; } while(0)

int square(int x);

int square_01() {
	int x = 5;
	_assert(square(x) == 25);
	return 0;
}

int square_02() {
	int x = 3;
	_assert(square(x) == 33);
	return 0;
}


int all_tests() {
	_verify(square_01);
	_verify(square_02);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}

int square(int x) {
	return x*x;
}
