class Solution {
private:
    bool col[9][10], row[9][10], chunk[9][10];
        int getChunk(int x, int y){
        return x / 3 * 3 + y / 3;
    }
        void hashKey(int x, int y, int key, bool val){
        row[x][key] = val;
        col[y][key] = val;
        chunk[getChunk(x, y)][key] = val;
    }
        bool dfs(vector<vector<char>>& board, int x, int y){
        if (y == 9){
            x ++;
            y = 0;
        }
        if (x == 9){
            return true;
        }
        if (board[x][y] != '.') return dfs(board, x, y + 1);
        for (int i = 1; i < 10; ++ i)
            if (row[x][i] == false &&
                col[y][i] == false &&
                chunk[getChunk(x, y)][i] == false){
                    hashKey(x, y, i, true);
                    board[x][y] = '0' + i;
                    if (dfs(board, x, y + 1) == true) return true;
                    hashKey(x, y, i, false);
                }
        board[x][y] = '.';
        return false;
    }
    public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(chunk, 0, sizeof(chunk));
        for (int i = 0; i < 9; ++ i)
            for (int j = 0; j < 9; ++ j)    
                if (board[i][j] != '.') hashKey(i, j, board[i][j] - '0', true);
        dfs(board, 0, 0);
    }
};