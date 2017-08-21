class Solution {
public:
    bool isScramble(string s1, string s2) {
        cout << s1 << ' ' << s2 << endl;
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        unordered_map<char, int> hash;
        for (auto& c : s1)
            hash[c] ++;
        for (auto& c : s2)
            hash[c] --;
        for (auto& p : hash)
            if (p.second > 0) return false;
        for (int i = 1; i < s1.size(); ++ i) {
            int len1 = i, len2 = s1.size() - len1;
            if (isScramble(s1.substr(0, len1), s2.substr(0, len1)) && isScramble(s1.substr(len1, len2), s2.substr
                (len1, len2))) return true;
            if (isScramble(s1.substr(0, len1), s2.substr(len2, len1)) && isScramble(s1.substr(len1, len2), s2
                .substr(0, len2))) return true;
        }
        return false;
    }
};