#include <stdio.h>

int main()
{
	int a = (1 << 31) - 1;
	printf("%d\n", a);
	
	++a;
	printf("%d\n", a);
	return 0;
}
