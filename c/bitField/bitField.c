#include <stdio.h>
#include <string.h>

struct {
	unsigned int widthValidated:	1;
	unsigned int heightValidated:	1;
} status;

struct {
	unsigned int widthValidated;
	unsigned int heightValidated;
} compare;

int main() {
	printf("Memory occupied by status: %ld\n", sizeof(status));
	printf("Memory occupied by compare: %ld\n", sizeof(compare));
	return 0;
}

