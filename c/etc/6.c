#include <stdio.h>

int main() {
	FILE *fp = fopen("test.txt", "r");
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fseek(fp, 0, SEEK_SET); // SEEK_SET points to the beginning of the file, SEEK_CUR the current position, SEEK_END the end.
	char c;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
