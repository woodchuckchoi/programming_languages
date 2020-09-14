#include <stdio.h>

int main() {
	const int LENGTH	=	10;
	const int WIDTH		=	5;
	const char NEWLINE	=	'\n';
	int area = LENGTH * WIDTH;

	printf("%d%c%c", area, NEWLINE, NEWLINE);
	return 0;
}
