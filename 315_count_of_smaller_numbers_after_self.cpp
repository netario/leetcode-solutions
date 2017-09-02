class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<pair<int, int>> s;
        for (int i = 0; i < nums.size(); ++ i)
            s.push_back(make_pair(nums[i], i));
        sort(s.begin(), s.end(), cmp);
        c.resize(nums.size() + 5, 0);
        for (int i = 0; i < nums.size(); ++ i){
            ret[s[i].second] = findSum(nums.size() - s[i].second);
            update(nums.size() - s[i].second);
        }
        return ret;
    }
private:
    static bool cmp(const pair<int, int> a, const pair<int, int> b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
        vector<int> c;
        int lowbit(int x){
        return x & (x ^ (x - 1));
    }
    void update(int pos){
        while(pos < c.size()){
          c[pos] += 1;
          pos += lowbit(pos);
        }
    }
    int findSum(int end){
        int ret = 0;
        while(end > 0){
            ret += c[end];
            end -= lowbit(end);
        }
        return ret;
    }
};