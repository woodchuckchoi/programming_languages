#include <stdio.h>

int main() {
	FILE *fp = fopen("test.txt", "r");
	char buf[20];
	if (fp == NULL) {
		printf("ERROR!\n");
		return 0;
	}
	fgets(buf, 20, fp);
	printf("%s\n", buf);
	fclose(fp);
	return 0;
}
