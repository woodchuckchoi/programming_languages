#include <stdio.h>

int main() {
	int num;
	char c;

	scanf("%d", &num);

	scanf("%c", NULL);
	printf("HERE\n");
	//scanf("%c", &c);
	getchar();
	printf("%d %c", num, c);
	return 0;
}
