#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *tmp;

	tmp = malloc(200*sizeof(char));

	if (tmp == NULL) {
		fprintf(stderr, "Unable to allocate required memory\n");
	} else {
		strcpy(tmp, "Being in a relationship is living both in heaven and hell at the same time");
	}

	printf("%s\n", tmp);
	free(tmp);
	return 0;
}
