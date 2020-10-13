#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *arr, int l, int h) {
	int p = *(arr+h);
	int i = l;
	for (int j = l; j < h; j++) {
		if (*(arr+j) < p) {
			swap(arr+j, arr+i);
			++i;
		}
	}
	swap(arr+i, arr+h);
	return i;
}

void quick_sort(int *arr, int l, int h) {
	if (l < h) {
		int p = partition(arr, l, h);
		quick_sort(arr, l, p-1);
		quick_sort(arr, p+1, h);
	}
}

int main() {
	int arr[] = {12,123,645,324,63,14,36};
	int len = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, len-1);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
