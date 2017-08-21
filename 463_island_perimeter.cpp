class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); ++ i)
            for (int j = 0; j < grid[0].size(); ++ j)
                if (grid[i][j] == 1){
                    for (int k = 0; k < 4; ++ k)
                        if (i + dx[k] < 0 || i + dx[k] >= grid.size() ||
                            j + dy[k] < 0 || j + dy[k] >= grid[0].size() ||
                            grid[i + dx[k]][j + dy[k]] != 1) ret ++;
                }
                        return ret;
    }
};