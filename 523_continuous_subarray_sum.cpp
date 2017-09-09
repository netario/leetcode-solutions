class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0;
        hash[sum] = -1;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            int m = k == 0 ? sum : sum % k;
            if (hash.count(m) == 0) { 
                hash[m] = i;
            } else {
                if (hash[m] != i - 1) return true;
            }           
        }
        return false;
    }
};