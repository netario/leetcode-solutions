class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0, tmp = 0;
        stack<int> stk;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') {
                stk.push(tmp + 1);
                tmp = 0;
            }
            if (s[i] == ')') {
                if (stk.size() > 0) {
                    tmp += stk.top() + 1;
                    stk.pop();
                    if (tmp > ret) ret = tmp;
                }
                else {
                    tmp = 0;
                }
            }
        }
        return ret;
    }
};