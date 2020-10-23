class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3) {
            return ans;
        }
        
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                
                if (nums[left] + nums[right] == 0 - nums[i]) {
                    ans.push_back({nums[i], nums[left++], nums[right--]});    
                    while (left < nums.size() - 1 && nums[left] == nums[left-1]) ++left;
                    while (right > 0 && nums[right] == nums[right+1]) --right;
                
                
                } else if (nums[left] + nums[right] < 0 - nums[i]) {
                    ++left;
                
                
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};
