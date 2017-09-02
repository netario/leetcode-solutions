class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs(n, 0, "", ret);
        return ret;
    }
private:
    void dfs(int c, int stk, string ans, vector<string> &ret){
        if (c == 0 && stk == 0){
            ret.push_back(ans);
            return;
        }
        if (c != 0) dfs(c - 1, stk + 1, ans + '(', ret);
        if (stk != 0) dfs(c, stk - 1, ans + ')', ret);
    }
};