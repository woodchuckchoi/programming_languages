#include <stdio.h>

int main() {
	float f;
	int i;

	scanf("%f", &f);
	i = f * 100 - ((int)f * 100);

	printf("%d", i);
	return 0;
}
