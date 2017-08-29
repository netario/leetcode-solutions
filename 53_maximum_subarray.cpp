class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int xmin = 0, xsum = 0;
        int ret = -1e09;
        for (int i = 0; i < nums.size(); i ++){
            xsum += nums[i];
            ret = max(ret, xsum - xmin);
            xmin = min(xmin, xsum);
        }
        return ret;
    }
};