class Solution {
public:
    static void dfs(int c, int n, vector<int> &nums, bool *h, vector<int> &tmp, vector<vector<int>> &ret){
        if (c > n){
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i ++)
            if (h[i] == false){
                h[i] = true;
                tmp.push_back(nums[i]);
                dfs(c + 1, n, nums, h, tmp, ret);
                tmp.pop_back();
                h[i] = false;
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        bool h[nums.size() + 5];
        memset(h, 0, sizeof(h));
        dfs(1, nums.size(), nums, h, tmp, ret);
        return ret;
    }
};