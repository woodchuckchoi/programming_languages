class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        
        for (int i = 0; i < bookings.size(); i++){
            if (bookings[i][1] == n) {
                ans[bookings[i][0]-1] += bookings[i][2];
            } else {
                ans[bookings[i][0]-1] += bookings[i][2];
                ans[bookings[i][1]] -= bookings[i][2];
            }
        }
        
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i-1];
        }
        return ans;
    }
};
