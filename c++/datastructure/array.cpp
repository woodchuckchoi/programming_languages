#include <bits/stdc++.h>
using namespace std;

int v[10];
int main() {
	for (int i = 0; i < 10; i++) v[i] = i;
	for (int a : v) cout << a << " ";
	cout << endl;

	auto a = find(v, v + 10, 100);
	if (a == v + 10) cout << "Not Found" << endl;

	a = find(v, v + 10, 5);
	cout << "Found " << *a << " at " << a << endl;

	fill(v, v + 10, 10);
	for (int a : v) cout << a << " ";
	cout << endl;

	return 0;
}
