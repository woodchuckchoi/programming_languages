class Solution {
public:
    int min(int a, int b) {
        if (a < b) return a;
        return b;
    }
    
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < s.size(); i++) {
            // odd
            int oneSide = min(i, s.size()-i-1);
            
            for (int j = 1; j <= oneSide; j++) {
                if (s[i-j] == s[i+j]) {
                    int curLength = 1 + 2 * j;
                    if (curLength > maxLen) {
                        maxLen = curLength;
                        start = i - j;
                    }
                } else {
                    break;
                }
            }
            
            // even
            if (i > 0) {
                int cr = i, cl = i-1;
                while (cl >= 0 && cr < s.size()) {
                    if (s[cl] == s[cr]) {
                        if (cr - cl + 1 > maxLen) {
                            maxLen = cr - cl + 1;
                            start = cl;
                        }
                        --cl;
                        ++cr;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
