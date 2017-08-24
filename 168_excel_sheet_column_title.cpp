class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        int tmp = n;
        while (tmp != 0) {
            ret = string(1, 'A' + (tmp - 1) % 26) + ret;
            tmp = (tmp - 1) / 26;
        }
        return ret;
    }
};