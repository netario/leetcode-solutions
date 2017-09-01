class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        dfs(0, ret, ans, nums);
        return ret;
    }
private:
    void dfs(int c, vector<vector<int>> &ret, vector<int> &ans, vector<int> &nums){
        if (c == nums.size()){
            ret.push_back(ans);
            return;
        }
        ans.push_back(nums[c]);
        dfs(c + 1, ret, ans, nums);
        ans.pop_back();
        int t = c + 1;
        while (t < nums.size() && nums[t] == nums[c]) t ++;
        dfs(t, ret, ans, nums);
    }
};