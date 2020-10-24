class Solution {
public:
    void solve(vector<string> &ans, string cur, int leftCount, int rightCount){
        if(leftCount == 0 && rightCount == 0) {
            ans.push_back(cur);
            return;
        }
        if(rightCount > 0) solve(ans, cur+")", leftCount, rightCount-1); //right can be added only if corresponding left already added
        if(leftCount > 0) solve(ans, cur+"(", leftCount-1, rightCount+1); //when add left, increment possibility of adding one right
		return;        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        solve(ans, cur, n, 0);
        return ans;
    }
};
