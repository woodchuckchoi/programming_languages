#include <stdio.h>

int max(int num1, int num2) {

	if (num1 > num2) return num1;
	return num2;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d is bigger than the other one", max(a, b));
	return 0;
}
