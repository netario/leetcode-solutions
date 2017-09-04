class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool h[1000000];
        memset(h, 0, sizeof(h));
        for (int i = 0; i < nums.size(); i ++) {
            h[nums[i]] = true;
        }
        for (int i = 0; i <= nums.size(); i ++)
            if (h[i] == false) return i;
    }
};