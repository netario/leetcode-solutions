class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        deque<pair<int, int>> q;
        for (int i = 0; i < board.size(); ++ i) {
            q.push_back(make_pair(i, 0));
            q.push_back(make_pair(i, (int)board[0].size() - 1));
        }
        for (int i = 0; i < board[0].size(); ++ i) {
            q.push_back(make_pair(0, i));
            q.push_back(make_pair((int)board.size() - 1, i));
        }
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            if (board[x][y] == 'O') {
                board[x][y] = '#';
                for (int i = 0; i < 4; ++ i) {
                    int tx = x + dx[i], ty = y + dy[i];
                    if (tx >= 0 && ty >= 0 && tx < board.size() && ty < board[0].size() && board[tx][ty] == 'O') {
                        q.push_back(make_pair(tx, ty));
                    }
                }
            }
            q.pop_front();
        }
        for (auto& r : board)
            for (auto& c : r) 
                c = (c == '#' ? 'O' : 'X');
    }
};