#include <stdio.h>
#include "swap.h"

int partition(int arr[], int l, int h) {
	int pivot = arr[h];
	int cursor = l;
	for (int i = l; i <= h - 1; i++) {
		if (arr[i] < pivot) {
			swap(arr, i, cursor);
			++cursor;
		}
	}
	swap(arr, cursor, h);
	return cursor;
}

void quick_sort(int arr[], int l, int h) {
	if (l < h) {
	int pivot = partition(arr, l, h);
	
	quick_sort(arr, l, pivot-1);
	quick_sort(arr, pivot+1, h);
	}
}

int main() {
	int arr[] = {312,634,433,3465,765,253,7,534,645,756,532,856,523,68,623};
	int size = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr, 0, size-1);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
