class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ret = "";
        for (int i = 0; i < nums.size(); ++ i){
            if (i > 0) ret += "/";
            if (i == 1 && nums.size() >= 3) ret += "(";
            ret += to_string(nums[i]);
            if (i + 1 == nums.size() && nums.size() >= 3) ret += ")";
        }
        return ret;
    }
};