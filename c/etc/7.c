#include <stdio.h>

int main() {
	FILE *fp = fopen("test.txt", "r");
	char c;
	int size = 0;
	/*
	fseek(fp, -2, SEEK_END);
	printf("%c", fgetc(fp));
	fseek(fp, -2, SEEK_CUR);
	printf("%c", fgetc(fp));
	fseek(fp, -2, SEEK_SET);
	printf("%c", fgetc(fp)); // SEEK_SET - n < 0 only means the beginning position
	*/
	while (fgetc(fp) != EOF) {
		++size;
	}
	printf("Size: %d\n",size);
	for (int i = 0; i < size; i++) {
		fseek(fp, -1*i-1, SEEK_END);
		printf("%c", fgetc(fp));
	}
	fclose(fp);
	printf("\nSEEK_END: %d\nSEEK_SET: %d\n", SEEK_END, SEEK_SET);
	return 0;
}
