#include <stdio.h>

void swap(int *arr, int i, int j) {
	int tmp = *(arr+i);
	*(arr+i) = *(arr+j);
	*(arr+j) = tmp;
}

void bubble(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		int cur = i;
		while (cur > 0) {
			if (*(arr+cur-1) > *(arr+cur)) {
				swap(arr, cur, cur-1);
			}
			--cur;
		}
	}
}

int main() {
	int arr[] = {34,46,2,45,754,23,45,42,3,64,24,7,75,53};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	bubble(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
