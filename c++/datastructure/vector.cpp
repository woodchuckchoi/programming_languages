#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for (int a : v) cout << a << " ";
	cout << endl;
	v.pop_back();

	for (int a : v) cout << a << " ";
	cout << endl;

	v.erase(v.begin(), v.begin() + 1);

	for (int a : v) cout << a << " ";
	cout << endl;

	auto a = find(v.begin(), v.end(), 100);
	if (a == v.end()) cout << "Not Found" << endl;

	fill(v.begin(), v.end(), 10);
	for (int a : v) cout << a << " ";
	cout << endl;
	v.clear();
	for (int a : v) cout << a << " ";
	cout << endl;

	return 0;
}
