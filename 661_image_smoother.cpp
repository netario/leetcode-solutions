class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ret(M);
        const int dx[9] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
        const int dy[9] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
        for (int i = 0; i < ret.size(); ++ i)
            for (int j = 0; j < ret[0].size(); ++ j) {
                int sum = 0, cnt = 0;
                for (int k = 0; k < 9; ++ k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < ret.size() && y < ret[0].size()) {
                        sum += M[x][y];
                        cnt ++;
                    }
                    ret[i][j] = sum / cnt;
                }
            }
        return ret;
    }
};