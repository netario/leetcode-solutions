class Solution {
public:
    int mySqrt(int x) {
        int p = 0, q = x, ret;
        while (p <= q){
            long long t = p + ((q - p) >> 1);
            if (t * t <= x){
                ret = t;
                p = t + 1;
            } else{
                q = t - 1;
            }
        }
        return ret;
    }
};