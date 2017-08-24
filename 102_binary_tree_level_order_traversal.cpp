/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        vector<pair<TreeNode*, int>> s;
        s.push_back(make_pair(root, 0));
        while (!s.empty()){
            if (s.back().second >= ret.size()) ret.push_back(vector<int>());
            ret[s.back().second].push_back(s.back().first->val);
            TreeNode *ln = s.back().first->left, *rn = s.back().first->right;
            int d = s.back().second;
            s.pop_back();
            if (rn) s.push_back(make_pair(rn, d + 1));
            if (ln) s.push_back(make_pair(ln, d + 1));
        }
        return ret;
    }
};