#include <stdio.h>

int min(int *arr, int size);
int euclid(int *arr, int size);

int main() {
	int arr[3] = {18, 24, 33};
	printf("%d", euclid(arr, 3));
	return 0;
}

int min(int *arr, int size) {
	int min = 0;
	for (int i = 1; i < size; i++) {
		if ((*(arr+1) != 0) && (*(arr+i) < *(arr+min))) {
			min = i;
		}
	}
	return min;
}

int euclid(int *arr, int size) {
	while (1) {
		char flag = 1;
		int min_idx = min(arr, size);
		for (int idx = 0; idx < size; idx++) {
			if (idx != min_idx) {
				*(arr+idx) = *(arr+idx) % *(arr+min_idx);
				if (*(arr+idx) != 0) {
				flag = 0;
				}
			}
			printf("%d ", *(arr+idx));
		}
		if (flag) {
			return *(arr+min_idx);
		}
	}
}
