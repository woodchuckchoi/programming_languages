class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        
        if (s.size() == 0) return 0;
        
        int ans = 1;
        int i = 0, j = 0;
        
        while (i < s.size() && j < s.size()) {
            char cur = s[j];
            ++m[cur];
            
            while (m[cur] > 1) {
                char ati = s[i];
                ++i;
                --m[ati];
            }
            ans = max(ans, j - i + 1);
            ++j;
        }        
        return ans;
    }
};
