// this source will only compile when -O flag is provided with GCC
#include <stdio.h>

__inline int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int main(int argc, char **argv) {
	printf("%d\n", max(3,2));
	return 0;
}
