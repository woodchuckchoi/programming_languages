#include <bits/stdc++.h>

using namespace std;

// Don't quite remember the question, it seemed quite similar to the bracket pairing question but different....
// will continue when i find it later

string solution(string &s) {
    queue<string> q;
    string ans;
    string tmp = "";
    int idx = 0;

    while (idx < s.size() && s[idx] != '(') {
        tmp += s[idx];
        ++idx;
    }

    if (idx == s.size()) {
        return  tmp;
    } else {
        q.push(tmp);
        tmp = "";
        ++idx;
    }

    while (idx < s.size()) {
        if (s[idx] == '(') {
            if (tmp != "") {
                q.push(tmp);
                tmp = "";
            }
        } else if (s[idx] == ')' {
            // get the previous string out from queue and 
            q.push(tmp);
            tmp = "";
        } else {
            tmp += s[idx];
        }
        ++idx;
    }
    
    return ans;
}

int main() {
    int total = 0, correct = 0;
    test(total, correct, solution, "1R2G3B", "RGGBBB");
    test(total, correct, solution, "RB(GB)", "RBGBBGB");
    test(total, correct, solution, "R2(GB)", "RGBGB");

    cout << correct << "/" << total << endl;
    return 0;
}

void test(int &total, int &correct, string func(string), string q, string ans) {
    ++total;
    if (func(q) == ans) {
        ++correct;
        cout << "Question " << q << " Correct!" << endl;
    } else {
        cout << "Question " << q << " Incorrect!" << endl;
    }
}

// NUM can be 1~9
// String can be one of those ('A', 'B', 'C')
// Parenthesis can be used
// 1R2G3B = RGGBBB
// RB(GB) = RBGBBGB
// R2(GB) = RGBGB
