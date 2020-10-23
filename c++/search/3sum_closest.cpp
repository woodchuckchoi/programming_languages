class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                cout << "i " << i << " left " << left << " right " << right << " closest " << closest << endl;
                if (nums[i] + nums[left] + nums[right] == target) {
                    return target;
                } else if (nums[i] + nums[left] + nums[right] < target) {
                    if (target - (nums[i] + nums[left] + nums[right]) < abs(target - closest)) {
                        closest = nums[i] + nums[left] + nums[right];
                    }
                    ++left;
                    
                    while (left < nums.size() - 1 && nums[left - 1] == nums[left])
                        ++left;
                } else {
                    if (nums[i] + nums[left] + nums[right] - target < abs(target - closest)) {
                        closest = nums[i] + nums[left] + nums[right];
                    }
                    --right;
                    while (right > 1 && nums[right + 1] == nums[right]) {
                        --right;
                    }
                }
            }
        }
        return closest;
    }
};
