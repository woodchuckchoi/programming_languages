#include <stdio.h>

void insertion_sort(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*(arr+i) > *(arr+j)) {
				int tmp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = tmp;
			}
		}
	}
}

int main() {
	int arr[] = {5,2,7,4,45,7,3,5,8,5,3,8,9,4,10};
	insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
	
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
