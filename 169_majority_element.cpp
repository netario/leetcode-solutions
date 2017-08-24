class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++ i){
            if (cnt == 0){
                cur = nums[i];
                cnt = 1;
            } else
            if (nums[i] == cur) cnt ++;
                        else    cnt --;
        }
        return cur;
    }
};