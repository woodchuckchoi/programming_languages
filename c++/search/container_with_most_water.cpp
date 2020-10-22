class Solution {
public:
    int maxArea(vector<int>& height) {
        int  i = 0, j = height.size() - 1;
        
        int mx = 0;
        
        while (i < j) {
            if (height[i] > height[j]) {
                mx = max(mx, height[j] * (j - i));
                --j;
            } else {
                mx = max(mx, height[i] * (j - i));
                ++i;
            }
        }
        return mx;
    }
};
