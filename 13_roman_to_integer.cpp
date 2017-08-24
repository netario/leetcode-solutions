class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r;
        r['I'] = 1;
        r['V'] = 5;
        r['X'] = 10;
        r['L'] = 50;
        r['C'] = 100;
        r['D'] = 500;
        r['M'] = 1000;
        int ret = 0, tmp = 0;
        for (int i = 0; i < s.size(); ++ i){
            if (i == 0 || r[s[i]] == r[s[i - 1]]){
                tmp += r[s[i]];
                continue;
            }
            if (r[s[i]] < r[s[i - 1]]){
                ret += tmp;
                tmp = r[s[i]];
            } else{
                tmp = r[s[i]] - tmp;
            }
        }
        ret += tmp;
        return ret;
    }
};