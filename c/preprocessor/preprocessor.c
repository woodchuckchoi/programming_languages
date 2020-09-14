#include <stdio.h>

#define WIDTH 10
#define HEIGHT 5
#define NEWLINE '\n'

int main() {
	int area = WIDTH * HEIGHT;
	printf("%d%c", area, NEWLINE);
	printf("And this?");
	return 0;
}
