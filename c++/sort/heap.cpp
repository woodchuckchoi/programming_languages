#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int *arr, int idx, int size) {
	int left = 2 * idx + 1, right = 2 * idx + 2;
	
	int smallest = idx;

	if (left < size && *(arr+left) < *(arr+smallest)) {
		smallest = left;
	}
	if (right < size && *(arr+right) < *(arr+smallest)) {
		smallest = right;
	}

	if (smallest != idx) {
		swap(arr+smallest, arr+idx);
		heapify(arr, smallest, size);
	}
}

void heap_sort(int *arr, int size) {
	for (int i = size/2; i > -1; --i) {
		heapify(arr, i, size);
	}

	while (size > 0) {
		swap(arr, arr+size-1);
		cout << *(arr+size-1) << " ";
		--size;
		heapify(arr, 0, size);
	}
}

int main() {
	int arr[] = {123,534,7,8,6,324,456,56,8,23,2341,346,47};
	int len = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr, len);
	cout << endl;
	return 0;
}
