class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[100];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s.length(); i ++){
            cnt[s[i] - 'a'] ++;
        }
        for (int i = 0; i < t.length(); i ++){
            cnt[t[i] - 'a'] --;
        }
        for (int i = 0; i < 30; i ++)
            if (cnt[i] != 0) return false;
        return true;
    }
};