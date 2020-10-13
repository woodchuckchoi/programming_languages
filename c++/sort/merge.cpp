#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int h) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = h - mid;

	int *left = (int *)malloc(sizeof(int) * n1);
	int *right = (int *)malloc(sizeof(int) * n2);

	for (int i = 0; i <n1; i++) {
		*(left + i) = *(arr + l + i);
	}

	for (int i = 0; i <n2; i++) {
		*(right + i) = *(arr + mid + i + 1);
	}

	i = 0; 
	j = 0; 
	k = l;

	while (i < n1 && j < n2) {
		if (*(left + i) < *(right + j)) {
			*(arr + k) = *(left + i);
			++i;
		} else {
			*(arr + k) = *(right + j);
			++j;
		}
		++k;
	}

	while (i < n1) {
		*(arr+k) = *(left + i);
		++i;
		++k;
	}

	while (j < n2) {
		*(arr+k) = *(right + j);
		++j;
		++k;
	}
}

void merge_sort(int *arr, int l, int h) {
	if (l < h) {
		int mid = (l + h)/2;

		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, h);

		merge(arr, l, mid, h);
	}
}

int main() {
	int arr[] = {312,6543,756,253,3,46,567,34,42};
	int len = sizeof(arr)/sizeof(arr[0]);

	merge_sort(arr, 0, len-1);

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
