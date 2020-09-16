#include <stdio.h>

void add_one(int (*arr)[5], int size);
void print_array(int *first, int size);

int main() {
	int arr[5][5] = {{0}, {0}, {0}, {0}, {0}};
	add_one(arr, 5);
	print_array(&(arr[0][0]), 25);
	return 0;
}

void add_one(int (*arr)[5], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] += 1;
		}
	}
}

void print_array(int *first, int size) {
	for (int i = 0; i < size; i++) {
		printf("%dth element: %d\n",i+1, *(first+i)); 
	}
}
