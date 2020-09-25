#include <stdio.h>

void *test(char target[]) {
	printf("%s\n", target);
}

void run(void *func(), char args[]) {
	func(args);
}

int main() {
	run(test, "will it");	
	printf("%p\n", test);
	return 0;
}
