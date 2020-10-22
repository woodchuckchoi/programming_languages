#include <bits/stdc++.h>
using namespace std;

int main() {
	char a = 'a';
	cout << a - (int)'a' << endl;


	return 0;
}

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        long long int num = 0;
        int idx = 0;
        bool neg = false;
        
        while (s[idx] == ' '){
            ++idx;
        }
        
        if (!((s[idx] >= '0' && s[idx] <= '9') || (s[idx] == '+') || (s[idx] == '-'))) {
            return 0;
        }
        
        if (s[idx] == '-' || s[idx] == '+') {
            if (s[idx] == '-') {
                neg = true;
            }
            ++idx;
        }
            
        
        while (s[idx] >= '0' && s[idx] <= '9') {
            if (num * 10 + (s[idx] - '0') > INT_MAX) {
                if (neg) {
                    num = INT_MIN;
                    neg = true;
                } else {
                    num = INT_MAX;
                }
                break;
            }
            num = num * 10 + (s[idx] - '0');
            ++idx;
        }
        
        if (neg) {
            num *= -1;
        }
        
        return (int)num;
    }
};
