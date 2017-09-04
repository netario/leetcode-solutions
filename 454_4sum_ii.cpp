class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret = 0;
        unordered_map<int, int> ab, cd;
        for (int i = 0; i < A.size(); ++ i)
            for (int j = 0; j < B.size(); ++ j)
                ab[A[i] + B[j]] ++;
        for (int i = 0; i < C.size(); ++ i)
            for (int j = 0; j < D.size(); ++ j)
                cd[C[i] + D[j]] ++;
        for (auto& p : ab)
            if (cd.count(-p.first) > 0) ret += p.second * cd[-p.first];
        return ret;
    }
};