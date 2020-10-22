#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int XMOVE[4] = {-1, 0, 1, 0};
int YMOVE[4] = {0, -1, 0, 1};

void heapify(vector<int> &v, int idx) {
	int lowest = idx;
	int left = 2 * idx + 1, right = 2 * idx + 2;
	
	if (left < v.size() && v[left] < v[lowest]) {
		lowest = left;
	}
	if (right < v.size() && v[right] < v[lowest]) {
		lowest = right;
	}
	
	if (lowest != idx) {
		swap(v[idx], v[lowest]);
		heapify(v, lowest);
	}
}

vector<int> heapSort(vector<int> &v) {
	vector<int> ans;
	
	for (int i = (v.size() / 2) - 1; i > -1; i--) {
		heapify(v, i);
	}
	
	while (!v.empty()) {
		swap(v[0], v[v.size()-1]);
		ans.push_back(v[v.size()-1]);
		v.pop_back();
		heapify(v, 0);
	}
	
	return ans;
}

int find(int sizeOfMatrix, int **matrix, int y, int x) {
	if (*(*(matrix + y) + x) == 0)
		return 0;
	
	*(*(matrix + y)+x) = 0;
	int val = 1;
	
	for (int i = 0; i < 4; i++) {
		if (y + YMOVE[i] >= 0 && y + YMOVE[i] < sizeOfMatrix && x + XMOVE[i] >= 0 && x + XMOVE[i] < sizeOfMatrix && *(*(matrix + y + YMOVE[i]) + x + XMOVE[i]) == 1) {
			val += find(sizeOfMatrix, matrix, y+YMOVE[i], x+XMOVE[i]);
		}
	}
	
	return val;
}

void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.
	vector<int> areas;
	
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			if (*(*(matrix+i)+j) == 1) {
				areas.push_back(find(sizeOfMatrix, matrix, i, j));
			}
		}
	}
	
	vector<int> ans = heapSort(areas);
	
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) {
			cout << ans[i] << endl;
		} else {
			cout << ans[i] << " ";
		}
	}
}

struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.sizeOfMatrix;

  inputData.matrix = new int*[inputData.sizeOfMatrix];
  for (int i = 0; i < inputData.sizeOfMatrix; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.matrix[i] = new int[inputData.sizeOfMatrix];
    for (int j = 0; j < inputData.sizeOfMatrix; j++) {
      iss >> inputData.matrix[i][j];
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}
