#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *tmp;
	tmp	= malloc(30*sizeof(char));

	if (tmp == NULL) {
		fprintf(stderr, "Unable to allocate required memory\n");
	} else {
		strcpy(tmp, "Bye\n");
	}

	tmp	= realloc(tmp, 100*sizeof(char));

	if (tmp == NULL) {
		fprintf(stderr, "Unable to allocate required memory\n");
	} else {
		strcat(tmp, "I\'ve always loved you");
	}

	printf("%s\n", tmp);

	free(tmp);
	return 0;
}
