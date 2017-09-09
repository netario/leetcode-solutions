class Solution {
public:
    void sortColors(vector<int>& nums) {
        int t0 = -1, t1 = -1, t2 = -1;
        for (int i = 0; i < nums.size(); ++ i){
            if (nums[i] == 0){
                nums[++ t2] = 2;
                nums[++ t1] = 1;
                nums[++ t0] = 0;
            } else
            if (nums[i] == 1){
                nums[++ t2] = 2;
                nums[++ t1] = 1;
            } else
            if (nums[i] == 2){
                nums[++ t2] = 2;
            }
        }
    }
};