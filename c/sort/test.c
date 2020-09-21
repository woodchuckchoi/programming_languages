#include <stdio.h>

void test(int n) {
	int test[n];
	for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
		printf("%d ", test[i]);
	}
}

int main() {
	test(3);
	return 0;
}
