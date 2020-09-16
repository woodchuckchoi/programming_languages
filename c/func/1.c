#include <stdio.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void descend(int* arr, int size) {
	for (int i = 0; i < size-1; i++) {
		for (int j = size-1; j > i; j--) {
			if (*(arr+j-1) < *(arr+j)) {
				swap(arr+j-1, arr+j);
			}
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
}

int main() {
	int arr[10] = {1,2,3,4,5,5,6,76,87,100};
	descend(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
