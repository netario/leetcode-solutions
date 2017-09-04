class Solution {
public:
    bool isHappy(int n) {
        bool h[1000];
        memset(h, 0, sizeof(h));
        while (n != 1) {
            int tmp = 0;
            while (n != 0) {
                tmp = tmp + pow(n % 10, 2);
                n = n / 10;
            }
            n = tmp;
            if (h[n] == true) return false;
            h[n] = true;
        }
        return true;
    }
};