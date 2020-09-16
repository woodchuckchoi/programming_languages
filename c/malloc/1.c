#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	printf("Input the size of the array: ");
	scanf("%d", &size);

	int *arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}
