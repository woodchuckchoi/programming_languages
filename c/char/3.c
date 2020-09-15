#include <stdio.h>

int main() {
	char ch;

	short sh;
	int i;
	long lo;

	float fl;
	double du;

	printf("ch\n");
	scanf("%c", &ch);

	printf("short\n");
	scanf("%hd", &sh);
	printf("int\n");
	scanf("%d", &i);
	printf("long\n");
	scanf("%ld", &lo);

	printf("float\n");
	scanf("%f", &fl);
	printf("double\n");
	scanf("%lf", &du);

	printf("char : %c , short : %d , int : %d ", ch, sh, i);
	printf("long : %ld , float : %f, double : %f \n", lo, fl, du);

	return 0;
}
