class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        a.push_back(1);
        for (int i = 0; i < nums.size(); ++ i)
            a.push_back(nums[i]);
        a.push_back(1);
        vector<vector<int>> f(a.size() + 5, vector<int>(a.size() + 5, 0));
        for (int k = 0; k <= n; ++ k)
            for (int i = 1; i <= n - k; ++ i){
                int p = i, q = i + k;
                for (int j = p; j <= q; ++ j)
                    f[p][q] = max(f[p][q], f[p][j - 1] + f[j + 1][q] + a[p - 1] * a[q + 1] * a[j]);
            }
        return f[1][n];
    }
};