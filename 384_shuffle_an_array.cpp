class Solution {
private:
    vector<int> bak;
public:
    Solution(vector<int> nums) {
        bak = nums;
        srand((int)time(0));
    }
        /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return bak;
    }
        /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(bak);
        for (int i = (int)ret.size() - 1; i > 0; -- i){
            int j = rand() % (i + 1);
            swap(ret[i], ret[j]);
        }
        return ret;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */