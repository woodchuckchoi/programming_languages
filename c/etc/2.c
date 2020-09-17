#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("test.txt", "w");

	if (fp == NULL) {
		printf("Write Error!\n");
		return 0;
	}

	fputs("test\n", fp);

	fclose(fp);
	return 0;
}
