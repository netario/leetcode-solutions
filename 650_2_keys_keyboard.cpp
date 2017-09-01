class Solution {
public:
    int minSteps(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[1] = 0;
        for (int i = 1; i < n; ++ i) {
            for (int j = i * 2, cnt = 2; j <= n; j += i, ++ cnt)
                f[j] = min(f[j], f[i] + cnt);
        }
        return f[n];
    }
};