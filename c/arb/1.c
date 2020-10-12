#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int x_diff[] = {0, 0, -1, 1};
int y_diff[] = {1, -1, 0, 0};

int arr[MAX_SIZE][MAX_SIZE];
int n;

int BFS(int y, int x);
void bubble_sort(int *ans, int size);

int main() {
	
	int ans[MAX_SIZE*MAX_SIZE] = {0,};
	int ans_size = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				int field = BFS(i, j);
				ans[ans_size] = field;
				ans_size++;
			}
		}
	}
	bubble_sort(ans, ans_size);

	printf("%d\n", ans_size);

	for (int i = 0; i < ans_size; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

/*
	printf("\nresult\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
*/
	return 0;
}

void bubble_sort(int *ans, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (*(ans+j) > *(ans+j+1)) {
				int tmp = *(ans+j);
				*(ans+j) = *(ans+j+1);
				*(ans+j+1) = tmp;
			}
		}
	}
}

int BFS(int y, int x) {
	if (arr[y][x] == 0)
		return 0;

	int field = 1;
	arr[y][x] = 0;

	for (int k = 0; k < 4; k++) {
		if ((y+y_diff[k] < n) && (y+y_diff[k] >= 0) && (x+x_diff[k] < n) && (x+x_diff[k] >= 0)) {
			field += BFS(y+y_diff[k], x+x_diff[k]);
		}
	}

	return field;
}
