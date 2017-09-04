class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> hash;
        for (auto& num : nums1)
            hash[num] ++;
        for (auto& num : nums2)
            if (hash.count(num) > 0 && hash[num] > 0){
                hash[num] --;
                ret.push_back(num);
            }
        return ret;
    }
};