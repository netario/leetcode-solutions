class Solution {
private:
    int cntSum(int n) {
        vector<int> fac(n + 1, 1);
        for (int i = 1; i <= n; ++ i)
            fac[i] = fac[i - 1] * i;
        int ret = 0;
        for (int i = 1; i <= n; ++ i)
            ret += i * fac[n] / fac[i] / fac[n - i] * pow(9, n - i);
        return ret;
    }
    public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        int ret = 0;
        string sn = to_string(n);
        for (int i = 0; i < sn.size(); ++ i) {
            int d = sn[i] - '0';
            if (d == 1) ret += (i + 1 == sn.size() ? 1 : stoi(sn.substr(i + 1, sn.size() - i - 1)) + 1);
            if (d > 1) ret += pow(10, sn.size() - i - 1);
            ret += d * cntSum(sn.size() - i - 1);
        }
        return ret;
    }
};