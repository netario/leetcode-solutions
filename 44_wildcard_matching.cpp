class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> f((int)s.size() + 5, vector<bool>((int)p.size() + 5, false));
        vector<int> rec(p.size() + 5, -1);
        f[0][0] = true;
        for (int i = 0; i <= s.size(); ++ i)
            for (int j = 0; j <= p.size(); ++ j)
                if (f[i][j] == true || (j != 0 && p[j - 1] == '*'&& rec[j - 1] == 1)){
                    f[i][j] = true;
                    if (j == p.size()) continue;
                    if (p[j] == '?'){
                        f[i + 1][j + 1] = true;
                    } else
                        if (p[j] == '*'){
                            rec[j] = 1;
                        } else
                            if (i != s.size() && s[i] == p[j]) f[i + 1][j + 1] = true;
                }
        return f[s.size()][p.size()];
    }
};