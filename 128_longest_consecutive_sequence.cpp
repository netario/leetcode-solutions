class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> hash;
        for (auto& num : nums)
            hash[num] ++;
        for (auto& p : hash)
            if (p.second > 0) {
                int cnt = 1;
                int tmp = p.first;
                while (hash.count(-- tmp) > 0 && hash[tmp] > 0) {
                    hash[tmp] = -1;
                    cnt ++;
                }
                tmp = p.first;
                while (hash.count(++ tmp) > 0 && hash[tmp] > 0) {
                    hash[tmp] = -1;
                    cnt ++;
                }
                ret = max(ret, cnt);
            }
        return ret;
    }
};