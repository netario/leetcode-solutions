class Solution {
public:
    int climbStairs(int n) {
        int ret = 0;
                int* f = new int[n + 5];
        for (int i = 0; i <= n; i ++) {
            f[i] = 0;
        }
        f[0] = 1;
        for (int i = 0; i <= n; i ++) {
            f[i + 1] += f[i];
            f[i + 2] += f[i];
        }
        ret = f[n];
        delete []f;
                return ret;
    }
};