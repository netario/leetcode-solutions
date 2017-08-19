class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> f(s.size() + 5, vector<bool>(p.size() + 5, false));
        f[0][0] = true;
        for (int i = 0; i <= s.size(); ++ i)
            for (int j = 0; j <= p.size(); ++ j)
                if (f[i][j] == true){
                    if (j != 0 && p[j - 1] == '*' && i < s.size() && (s[i] == p[j - 2] || p[j - 2] == '.')) f[i + 
                        1][j] = true;
                    if (j + 1 < p.size() && p[j + 1] == '*') {
                        f[i][j + 2] = true;
                        continue;
                    }
                    if (i < s.size() && j < p.size() && (s[i] == p[j] || p[j] == '.')) f[i + 1][j + 1] = true;
                }
        return f[s.size()][p.size()];
    }
};