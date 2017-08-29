class Solution {
public:
    int nextGreaterElement(int n) {
        string sn = to_string(n);
        for (int i = (int)sn.size() - 2; i >= 0; -- i)
            if (sn[i] < sn[i + 1]) {
                int j;
                for (j = i + 1; j < sn.size(); ++ j)
                    if (sn[j] <= sn[i]) break;
                swap(sn[i], sn[j - 1]);
                reverse(sn.begin() + i + 1, sn.end());
                long ret = stol(sn);
                return ret <= INT_MAX ? (int)ret : -1;
            }
        return -1;
    }
};