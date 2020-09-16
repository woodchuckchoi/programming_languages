#include <stdio.h>
#include <stdlib.h>

int main() {
	int **arr;
	int x, y;

	printf("Size of the 2-Dimensional Array [x] [y]: ");
	scanf("%d %d", &x, &y);

	arr = (int **)malloc(sizeof(int *) * x);

	for (int i = 0; i < x; ++i) {
		arr[i] = (int *)malloc(sizeof(int) * y);
	}

	for (int i = 0; i < x; ++i) {
		free(arr[i]);
	}
	free(arr);
	return 0;
}
