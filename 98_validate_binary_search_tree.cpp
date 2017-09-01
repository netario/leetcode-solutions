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
    bool dfs(TreeNode* root, long long l, long long r){
        if (!root) return true;
        if (root->val < l || root->val > r) return false;
        return dfs(root->left, l, (long long)root->val - 1) && dfs(root->right, (long long)root->val + 1, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};