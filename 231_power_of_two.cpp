class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        long long x = n;
        return x == (((x^(x - 1)) + 1) >> 1);
    }
};