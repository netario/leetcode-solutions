class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int tmp = 1;
        for (int i = 0; i < nums.size(); ++ i){
            ret[i] *= tmp;
            tmp *= nums[i];
        }
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; -- i){
            ret[i] *= tmp;
            tmp *= nums[i];
        }
        return ret;
    }
};