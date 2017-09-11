class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});
        vector<int> f(1, INT_MIN);
        for (int i = 0; i < pairs.size(); ++ i) {
            int p = 0, q = (int)f.size() - 1, ans = 1;
            while (p <= q) {
                int mid = p + (q - p) / 2;
                if (f[mid] < pairs[i][0]) {
                    ans = mid + 1;
                    p = mid + 1;
                } else {
                    q = mid - 1;
                }
            }
            if (ans == f.size()) {
                f.push_back(pairs[i][1]);
            } else {
                f[ans] = min(f[ans], pairs[i][1]);
            }
        }
        return (int)f.size() - 1;
    }
};