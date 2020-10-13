#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
/*
	cin >> n; cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		string ret = "";
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ' || s[i] == '\n') {
				sum += atoi(ret.c_str());
				ret = "";
			} else {
				ret += s[i];
			}
		}
		if (ret != "") sum += atoi(ret.c_str());
		cout << sum << "\n";
	}
*/
	cin >> n; cin.ignore();
	cout << endl;
	while (n--) {
		string s;
		getline(cin, s);
		int sum = 0;
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ' || s[i] == EOF) {
				sum += atoi(tmp.c_str());
				tmp = "";
			} else {
				tmp += s[i];
			}
		}
		if (tmp != "") sum += atoi(tmp.c_str());
		cout << sum << endl;
	}
	return 0;
}
