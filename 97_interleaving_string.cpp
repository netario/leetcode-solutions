class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> f(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= s1.size(); ++ i)
            for (int j = 0; j <= s2.size(); ++ j) {
                if (i != 0 && s1[i - 1] == s3[i + j -1] && f[i - 1][j]) f[i][j] = true;
                if (j != 0 && s2[j - 1] == s3[i + j -1] && f[i][j - 1]) f[i][j] = true;
            }
        return f[s1.size()][s2.size()];
    }
};