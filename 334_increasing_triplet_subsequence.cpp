class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> f = {INT_MIN, INT_MAX, INT_MAX, INT_MAX};
        for (auto& num : nums) {
            for (int i = 0; i < 3; ++ i)
                if (num > f[i] && num < f[i + 1]) f[i + 1] = num;
            if (f[3] != INT_MAX) return true;
        }
        return false;
    }
};