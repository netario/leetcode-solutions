class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> p, q;
        p[0] ++;
        for (int i = 0; i < nums.size(); ++ i) {
            q.clear();
            for (auto& pair : p) {
                q[pair.first + nums[i]] += pair.second;
                q[pair.first - nums[i]] += pair.second;
            }
            swap(p, q);
        }
        return p[S];
    }
};