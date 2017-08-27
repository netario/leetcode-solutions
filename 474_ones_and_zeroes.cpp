class Solution {
private:
    int f[2][102][102];
    public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(f, -1, sizeof(f));
        f[0][0][0] = 0;
        int p = 0, q = 1;
        for (int i = 0; i < strs.size(); ++ i){
            memset(f[q], -1, sizeof(f[q]));
            int cnt_m = 0, cnt_n = 0;
            for (int j = 0; j < strs[i].size(); ++ j){
                cnt_m += (strs[i][j] == '0');
                cnt_n += (strs[i][j] == '1');
            }
            for (int j = 0; j <= m; ++ j)
                for (int k = 0; k <= n; ++ k)
                    if (f[p][j][k] != -1){
                        f[q][j][k] = max(f[q][j][k], f[p][j][k]);
                        if (j + cnt_m <= m && k + cnt_n <= n)
                            f[q][j + cnt_m][k + cnt_n] = max(f[q][j + cnt_m][k + cnt_n], f[p][j][k] + 1);
                    }
            p ^= 1;
            q ^= 1;
        }
                int ret = 0;
        for (int j = 0; j <= m; ++ j)
            for (int k = 0; k <= n; ++ k)
                ret = max(ret, f[p][j][k]);
        return ret;
    }
};