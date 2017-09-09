class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        int n = x ^ y;
        while (n){
            n &= n - 1;
            ret ++;
        }
        return ret;
    }
};