class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        int res = 0;
        for (auto& num : nums)
             res ^= num;
        int tmp = res ^ (res - 1) & res, x1 = 0, x2 = 0;
        for (auto& num : nums){
            if ((num & tmp) == tmp) x1 ^= num;
                            else  x2 ^= num;
        }
        ret.push_back(x1);
        ret.push_back(x2);
        return ret;
    }
};