class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> hash;
        for (auto& num : nums)
            hash[num] ++;
        vector<pair<int, int>> arr;
        for (auto& p : hash)
            arr.push_back(p);
        sort(arr.begin(), arr.end(), 
             [](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
        for (int i = 0; i < k; ++ i)
            ret.push_back(arr[i].first);
        return ret;
    }
};