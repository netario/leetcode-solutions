class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        ret.push_back(1);
        int u = 1;
        for (int i = k; i > 0; -- i) {
            ret.push_back(ret.back() + u * i);
            u = -u;
        }
        for (int i = k + 2; i <= n; ++ i)
            ret.push_back(i);
        return ret;
    }
};