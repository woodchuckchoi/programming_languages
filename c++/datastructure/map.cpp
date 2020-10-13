#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> m;
	m["test"] = 1;
	m["next"] = 2;
	for (auto e : m) {
		cout << e.first << " = " << e.second << endl;
	}
	cout << m["none"] << endl;
	m["none"]++;
	cout << m["none"] << endl;
	return 0;
}
