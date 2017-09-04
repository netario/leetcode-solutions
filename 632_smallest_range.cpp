class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) { 
        auto cmp = [&nums](pair<int, int>& a, pair<int, int>& b) { return nums[a.first][a.second] > nums[b
            .first][b.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < nums.size(); ++ i) {
            q.push(make_pair(i, 0));
            lo = min(nums[i][0], lo);
            hi = max(nums[i][0], hi);
        }
        vector<int> ret = {lo, hi};
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            if (p.second + 1 == nums[p.first].size()) break;
            q.push(make_pair(p.first, p.second + 1));
            lo = nums[q.top().first][q.top().second];
            hi = max(nums[p.first][p.second + 1], hi);
            if (hi - lo >= ret[1] - ret[0]) continue;
            ret = {lo, hi};
        }
        return ret;
    }
};