class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++ i){
            while (!q.empty() && q.front().first < i - k + 1) 
                q.pop_front();
            while (!q.empty() && q.back().second <= nums[i])
                q.pop_back();
            q.push_back(make_pair(i, nums[i]));
            if (i >= k - 1) ret.push_back(q.front().second);
        }
        return ret;
    }
};