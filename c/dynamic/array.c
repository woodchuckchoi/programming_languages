#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char **texts;
	int i;

	texts	= malloc(30*sizeof(void*));
	
	for (i = 0; i < 30; i++) {
		texts[i] = malloc(10*sizeof(char));
		strcpy(texts[i], "hiyo");
	}

	for (i = 0; i < 30; i++) {
		printf("%s\n", texts[i]);
	}

	return 0;
}
