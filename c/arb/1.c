#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_SIZE = 10;

int x_diff[] = {0, 0, -1, 1};
int y_diff[] = {1, -1, 0, 0};

int main() {
	int n;
	int arr[MAX_SIZE][MAX_SIZE];
	
	int ans[MAX_SIZE*MAX_SIZE] = {0,};
	int ans_idx = 2;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				char flag = 0;
				for (int k = 0; k < 4; k++) {
					if ((i+y_diff[k] < n) && (i+y_diff[k] >= 0) && (j+x_diff[k] < n) && (j+y_diff[k] >= 0)) {
						if ((size == 0) && (arr[i+y_diff[k]][j+x_diff[k]] = 1))
		// THIS IS WRONG, IT MUST BE MUCH EASIER TO SOLVE WITH BFS/DFS, DO IT TOMORROW!
		}
	}
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
