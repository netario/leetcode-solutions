class Solution {
public:
    int getSum(int a, int b) {
        while ((a & b) != 0){
            int c = (a ^ b);
            b = ((a & b) << 1);
            a = c;
        }
        return a ^ b;
    }
};