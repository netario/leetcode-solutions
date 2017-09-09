class Solution {
private:
    int rec[100000];
    public:
    int findMaxLength(vector<int>& nums) {
        memset(rec, -1, sizeof(rec));
        rec[50000] = 0;
        int ret = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++ i){
            if (nums[i] == 1) cnt ++;
                        else  cnt --;
            if (rec[cnt + 50000] == -1) rec[cnt + 50000] = i + 1;
                                else    ret = max(ret, i + 1 - rec[cnt + 50000]);
        }
        return ret;
    }
};