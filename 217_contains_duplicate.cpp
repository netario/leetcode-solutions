class Solution {
public:
    static bool cmp(int a, int b) {
        return a < b;
    }
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it ++) {
            if ((it + 1) == nums.end()) continue;
            if (*it == *(it + 1)) return true;
        }
    return false;
    }
};