class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        int f[s.size() + 6];
        memset(f, 0, sizeof(f));
        if (s.size() > 0 && s[0] != '0') f[0] = 1;
        if (s.size() > 1 && s[1] != '0') f[1] = f[0];
        if (s.size() > 1 && (s[0] - '0') * 10 + (s[1] - '0') <= 26 && (s[0] - '0') * 10 + (s[1] - '0') >= 10) f[1] 
            += 1;
        for (int i = 2; i < s.size(); i ++){
            if (s[i] != '0') f[i] += f[i - 1];
            if ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 26 && (s[i - 1] - '0') * 10 + (s[i] - '0') >= 10) f[i] += 
                f[i - 2];
        }
        return f[s.size() - 1];
    }
};