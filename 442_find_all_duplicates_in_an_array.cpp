class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for (auto& num : nums)
            nums[(num - 1) % nums.size()] = nums[(num - 1) % nums.size()] + nums.size();
        for (int i = 0; i < nums.size(); ++ i)
            if ((nums[i] - 1) / nums.size() == 2) ret.push_back(i + 1);
        for (auto& num : nums)
            num = (num - 1) % nums.size() + 1;
        return ret;
    }
};