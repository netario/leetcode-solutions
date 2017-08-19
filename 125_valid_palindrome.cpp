class Solution {
public:
    bool isPalindrome(string s) {
        int p = 0, q = s.size() - 1;
        while (p < q){
            while (p < s.size() && !(tolower(s[p]) >= 'a' && tolower(s[p]) <= 'z' || s[p] >='0' && s[p] <= '9')) p 
                ++;
            while (q >= 0 && !(tolower(s[q]) >= 'a' && tolower(s[q]) <= 'z' || s[q] >='0' && s[q] <= '9')) q --;
            if (p < q && tolower(s[p]) != tolower(s[q])) return false;
            p ++;
            q --;
        }
        return true;
    }
};