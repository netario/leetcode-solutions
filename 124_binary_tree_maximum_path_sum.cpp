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
private:
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;
        int nl = dfs(root->left, ans), nr = dfs(root->right, ans);
        ans = max(ans, (nl < 0 ? 0 : nl) + (nr < 0 ? 0 : nr) + root->val);
        return max(max(nl + root->val, nr + root->val), root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};