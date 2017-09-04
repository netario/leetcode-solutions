class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        if (matrix.empty()) return ret;
        vector<vector<int>> f(matrix.size(), vector<int>(matrix[0].size(), 1));
        deque<pair<int, int>> deq;
        for (int i = 0; i < matrix.size(); ++ i)
            for (int j = 0; j < matrix[0].size(); ++ j)
                deq.push_back(make_pair(i, j));
        const int dx[4] = {0, 0, 1, -1},
                  dy[4] = {1, -1, 0, 0};
        while (!deq.empty()) {
            int x = deq.front().first, y = deq.front().second;
            deq.pop_front();
            ret = max(ret, f[x][y]);
            for (int i = 0; i < 4; ++ i) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= f.size() || ty < 0 || ty >= f[0].size() || 
                    matrix[tx][ty] <= matrix[x][y] || f[tx][ty] >= f[x][y]  + 1) continue;
                f[tx][ty] = f[x][y] + 1;
                deq.push_back(make_pair(tx, ty));
            }
        }
        return ret;
     }
};