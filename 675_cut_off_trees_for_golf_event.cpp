class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0][0] == 0) return -1;
        int ret = 0;
        vector<pair<int, int>> q;
        for (int i = 0; i < forest.size(); ++ i)
            for (int j = 0; j < forest[0].size(); ++ j)
                if (forest[i][j] > 1) q.push_back(make_pair(i, j));
        sort(q.begin(), q.end(), [&forest](pair<int, int> a, pair<int, int> b) 
                                 { return forest[a.first][a.second] < forest[b.first][b.second]; } );
        int x = 0, y = 0;
        const int dx[4] = {0, 0, 1, -1},
                  dy[4] = {1, -1, 0, 0};
        int f[52][52];
        for (auto& p : q) {
            memset(f, -1, sizeof(f));
            deque<pair<int, int>> que;
            que.push_back(make_pair(x, y));
            f[x][y] = 0;
            while (!que.empty()) {
                int cx = que.front().first, cy = que.front().second;
                que.pop_front();
                for (int i = 0; i < 4; ++ i) {
                    int tx = cx + dx[i], ty = cy + dy[i];
                    if (tx < 0 || tx >= forest.size() || ty < 0 || ty >= forest[0].size() || forest[tx][ty] == 0) 
                        continue;
                    if (f[tx][ty] == -1 || f[tx][ty] > f[cx][cy] + 1) {
                        f[tx][ty] = f[cx][cy] + 1;
                        que.push_back(make_pair(tx, ty));
                    }
                }
                            }
            x = p.first;
            y = p.second;
            if (f[x][y] == -1) return -1;
            ret += f[x][y];
        }
        return ret;
    }
};