#include <stdio.h>

int main() {
	int a = 6;
	int b = 3;
	// int* const p = &a; constant value that is a pointer to an int value
	const int* p = &a; // pointer to an int value that is a constant
	p = &b;
	return 0;
}
