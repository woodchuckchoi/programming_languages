#include <bits/stdc++.h>
using namespace std;

int main() {
	double ret = 2.12345;
	int n = 2;
	int a = (int)round(ret / double(n));
	int b = int(round(ret / double(n)));
	cout << a << endl;
	cout << b << endl << int(ret) << endl;

	double p = 123.343;
	int r = (int) p * 100;
	int t = (int) 100 * p;
	cout << "r = " << r << endl << "t = " << t << endl;

	return 0;
}
