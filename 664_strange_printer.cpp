class Solution {
private:
    int f[105][105];
        int dfs(string& s, int l, int r) {
        if (l > r) return 0;
        if (f[l][r] != -1) return f[l][r];
        f[l][r] = min(r - l + 1, min(dfs(s, l, r - 1) + 1, dfs(s, l + 1, r) + 1));
        for (int i = l; i < r; ++ i)
            if (s[i] == s[r]) f[l][r] = min(f[l][r], dfs(s, l, i) + dfs(s, i + 1, r - 1));
        return f[l][r];
    }
    public:
    int strangePrinter(string s) {
        memset(f, -1, sizeof(f));
        return dfs(s, 0, (int)s.size() - 1);
    }
};