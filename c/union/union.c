#include <stdio.h>
#include <string.h>

union Data {
	int i;
	float f;
	char str[20];
};

int main() {
	union Data tmp;

	printf("Memory size: %ld\n", sizeof(tmp));

	tmp.i = 10;
	printf("Memory size: %ld\n", sizeof(tmp));
	tmp.f = 200.5;
	printf("Memory size: %ld\n", sizeof(tmp));
	strcpy(tmp.str, "C programming");
	printf("Memory size: %ld\n", sizeof(tmp));
	return 0;
}
