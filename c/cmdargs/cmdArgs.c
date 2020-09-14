#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc == 2) {
		printf("%s\n", argv[1]);
	} else if (argc > 2) {
		printf("Too many arguments\n");
	} else {
		printf("Too few arguments\n");
	}
	return 0;
}
