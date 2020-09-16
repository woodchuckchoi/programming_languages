#include <stdio.h>

int str_length(char *);

int main() {
	char str[] = {"something this is"};
	printf("length of str: %d", str_length(str)); 

	return 0;
}

int str_length(char *str) {
	int idx = 0;
	while (1) {
		if (*(str + idx) != 0) {
			++idx;
		} else {
			break;
		}
	}
	return idx;
}
