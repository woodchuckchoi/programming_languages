#include <stdio.h>

int main() {
	int a, b;
	float c, d;

	scanf("%d %d", &a, &b);
	
	c = a / b;
	d = (float) a / b;

	printf("%f %f", c, d);

	return 0;
}
