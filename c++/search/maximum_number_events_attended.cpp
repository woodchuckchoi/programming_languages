class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int lastDay = 0;
        for (vector<int> &e : events) {
            lastDay = max(lastDay, e[1]);
        }
        
        int ans = 0;
        priority_queue<int> Q;
        
        for (int i = 0, curDay = 1; curDay <= lastDay; curDay++) {
            // add
            while (i < events.size() && events[i][0] == curDay) {
                Q.push(-events[i][1]);
                ++i;
            }
            
            // remove
            while (!Q.empty() && -Q.top() < curDay) {
                Q.pop();
            }
            
            // attend
            if (!Q.empty()) {
                Q.pop();
                ++ans;
            }
        }
        return ans;
    }
};
