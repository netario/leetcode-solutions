class Solution {
public:
    string longestPalindrome(string s) {
        int p = 0, q = 0;
        for (int i = 0; i < s.size(); ++ i){
            for (int j = 0; i + j < s.size() && i - j >= 0 && s[i + j] == s[i - j]; ++ j)
                if (1 + 2 * j > q - p + 1){
                    p = i - j;
                    q = i + j;
                }
            for (int j = 0; i + 1 + j < s.size() && i - j >= 0 && s[i + 1 + j] == s[i - j]; ++ j)
                if (2 + 2 * j > q - p + 1){
                    p = i - j;
                    q = i + 1 + j;
                }
        }
        return s.substr(p, q - p + 1);
    }
};