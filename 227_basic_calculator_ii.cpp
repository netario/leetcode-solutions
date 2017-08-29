class Solution {
private:
    void compress(stack<pair<int, char>>& stk) {
        pair<int, char> cur = stk.top();
        stk.pop();
        while (!stk.empty()) {
            pair<int, int> pre = stk.top();
            if ((pre.second == '+' || pre.second == '-') && (cur.second == '*' || cur.second == '/')) break;
            stk.pop();
            if (pre.second == '+') 
                cur = make_pair(pre.first + cur.first, cur.second);
            else if (pre.second == '-')
                cur = make_pair(pre.first - cur.first, cur.second);
            else if (pre.second == '*')
                cur = make_pair(pre.first * cur.first, cur.second);
            else if (pre.second == '/')
                cur = make_pair(pre.first / cur.first, cur.second);
                    }
        stk.push(cur);
    }
public:
    int calculate(string s) {
        stack<pair<int, char>> stk;
        s = s + '+';
        int tmp = 0;
        for (auto& c : s) {
            if (c == ' ') continue;
            if (c >= '0' && c <= '9') {
                tmp = tmp * 10 + c - '0';
                continue;
            }
            stk.push(make_pair(tmp, c));
            tmp = 0;
            compress(stk);
        }
        compress(stk);
        return stk.top().first;
    }
};