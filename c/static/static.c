#include <stdio.h>

static int count = 5;

void func();

int main() {
	while (count--) {
		func();
	}
	return 0;
}

void func() {
	static int result = 0;
	printf("Count %d Result %d\n", count, result);
	result += 2;
}
