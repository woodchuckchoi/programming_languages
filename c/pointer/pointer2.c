#include <stdio.h>

int main() {
	int var = 20;
	int *ip;

	ip = &var;

	printf("%p == %p != %d", &var, ip, *ip);

	return 0;
}
