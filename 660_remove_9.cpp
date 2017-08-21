class Solution {
public:
    int newInteger(int n) {
        int ret = 0, x = 0;
        while (n > 0) {
            ret += n % 9 * pow(10, x ++);
            n /= 9;
        }
        return ret;
    }
};