#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int xMove[4] = {0, 0, 1, -1};
const int yMove[4] = {1, -1, 0, 0};

int search(int **matrix, int size, int x, int y) {
	if (*(*(matrix + y) + x) == 0) {
		return 0;
	}
	
	int val = 1;
	*(*(matrix + y)+x) = 0;
	for (int i = 0; i < 4; i++) {
		if (y + yMove[i] < size && y + yMove[i] >= 0 && x + xMove[i] < size && x + xMove[i] >= 0) {
			val += search(matrix, size, x+xMove[i], y+yMove[i]);
		}
	}
	
	return val;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *arr, int l, int h) {
	int pivot = *(arr + h);
	int cursor = l;
	for (int i = l; i < h; i++) {
		if (*(arr+i) < pivot) {
			swap(arr+i, arr+cursor);
			++cursor;
		}
	}
	swap(arr+h, arr+cursor);
	return cursor;
}

void quick_sort(int *arr, int l, int h) {
	if (l < h) {
		int pivot = partition(arr, l, h);
		
		quick_sort(arr, l, pivot-1);
		quick_sort(arr, pivot+1, h);
	}
}

void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.
	
	int cnt = 0;
	int ans[100] = {0};
	
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			if (*(*(matrix + i) + j) == 1) {
				ans[cnt] = search(matrix, sizeOfMatrix, j, i);
				++cnt;
			}
		}
	}
	quick_sort(ans, 0, cnt-1);
	
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", ans[i]);
	}
}

struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data *inputData) {
  int j = 0;
  size_t linecap = 0;
  char *line = NULL, *brkt = NULL, *token = NULL, *sep = " \n";

  getline(&line, &linecap, stdin);
  inputData->sizeOfMatrix = atoi(line);

  inputData->matrix = calloc(inputData->sizeOfMatrix, sizeof(int *));
  for (int i = 0; i < inputData->sizeOfMatrix; i++) {
    getline(&line, &linecap, stdin);
    inputData->matrix[i] = calloc(inputData->sizeOfMatrix, sizeof(int));
    for (j = 0, token = strtok_r(line, sep, &brkt); j < inputData->sizeOfMatrix && token != NULL; j++, token = strtok_r(NULL, sep, &brkt)) {
      inputData->matrix[i][j] = atoi(token);
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(&inputData);

  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}
