class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> f;
        int l = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            f.push_back(make_pair(1, 1));
            for (int j = 0; j < i; ++ j)
                if (nums[j] < nums[i]) {
                    if (f[j].first + 1 > f[i].first) {
                        f[i] = make_pair(f[j].first + 1, f[j].second);
                    } else if (f[j].first + 1 == f[i].first) {
                        f[i] = make_pair(f[i].first, f[i].second + f[j].second);    
                    }
                }
            l = max(l, f[i].first);
        }
        int ret = 0;
        for (int i = 0; i < f.size(); ++ i) 
            if (f[i].first == l) ret += f[i].second;
        return ret;
    }
};