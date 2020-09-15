#include <stdio.h>

int main() {
	int arr[10] = {1,2,3,5};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}
