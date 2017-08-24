class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i ++){
            string tmp = "";
            int num = 0;
            for (int j = 0; j < s.size(); j ++){
                num ++;
                if (s[j] == s.size() - 1 || s[j] != s[j + 1]){
                    tmp += char(num + '0');
                    tmp += s[j];
                    num = 0;
                }
            }
            s = tmp;
        }
        return s;
    }
};