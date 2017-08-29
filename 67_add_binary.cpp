class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) a.swap(b);
        b = string(a.size() - b.size(), '0') + b;
        int u = 0;
        for (int i = a.size() - 1; i >= 0; i --){
            int tmp = (a[i] - '0') + (b[i] - '0') + u;
            u = 0;
            if (tmp > 1){
                u = tmp / 2;
                tmp = tmp % 2;
            }
            a[i] = tmp + '0';
        }
        if (u > 0) a = "1" + a;
        return a;
    }
};