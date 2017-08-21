class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++ i)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        for (int i = 0; i < nums.size(); ++ i)
            if (nums[i] > 0){
                ret.push_back(i + 1);
            }
            else{
                nums[i] = -nums[i];
            }
        return ret;
    }
};