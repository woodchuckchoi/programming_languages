#include <stdio.h>

void input(int (*)[3]);
void sort(int (*)[3]);
void output(int (*)[3]);
void swap(int (*)[3], int, int);

int main() {
	int users[5][3];

	input(users);
	sort(users);
	output(users);

	return 0;
}

void input(int (*arr)[3]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]); 
		}
	}
}
void sort(int (*arr)[3]) {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			int cur_highest = ((float)(arr[i][0] + arr[i][1] + arr[i][2]))/3;
			int cursor = ((float)(arr[j][0] + arr[j][1] + arr[j][2]))/3;
			if (cursor > cur_highest) {
				swap(arr, i, j);
			}
		}
	}
}
void output(int (*arr)[3]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void swap(int (*arr)[3], int i, int j) {
	int tmp[3];
	for (int idx = 0; idx < 3; idx++) {
		tmp[idx] = arr[i][idx];
	}
	for (int idx = 0; idx < 3; idx++) {
		arr[i][idx] = arr[j][idx];
	}
	for (int idx = 0; idx < 3; idx++) {
		arr[j][idx] = tmp[idx];
	}
}
