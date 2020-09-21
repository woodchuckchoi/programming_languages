#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int h) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = h - m;

	int *left = (int *)malloc(sizeof(int)*n1);
	int *right = (int *)malloc(sizeof(int)*n2);

	for (i = 0; i < n1; i++)
		*(left+i) = arr[l+i];
	for (j = 0; j < n2; j++)
		*(right+j) = arr[m+1+j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (*(left + i) < *(right + j)) {
			*(arr+k) = *(left + i);
			++i;
		} else {
			*(arr+k) = *(right + j);
			++j;
		}
		++k;
	}

	while (i < n1) {
		*(arr+k) = *(left+i);
		++i;
		++k;
	}
	while (j < n2) {
		*(arr+k) = *(right+j);
		++j;
		++k;
	}
}

void merge_sort(int arr[], int l, int h) {
	if (l < h) {
		int mid = (l + h)/2;
		merge_sort(arr, l, mid); // including the right boundary
		merge_sort(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}

int main() {
	int arr[] = {1,5,653,23,645,5243,4,65,532,14,346,475,532,8,364,865,5,856,43,524,635};
	int size = sizeof(arr)/sizeof(arr[0]);

	merge_sort(arr, 0, size-1);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

