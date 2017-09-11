class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        long long pre = -1 + INT_MIN;
        int ret = 0, cnt = 0;
        for (auto& num : nums) {
            if (pre < num) 
                cnt ++;
            else 
                cnt = 1;
            ret = max(ret, cnt);
            pre = num;
        }
        return ret;
    }
};