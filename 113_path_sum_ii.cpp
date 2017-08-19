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
    void dfs(TreeNode* root, int sum, vector<int>& ans, vector<vector<int>>& ret) {
        if (!root) return;
        ans.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right) ret.push_back(ans);
        dfs(root->left, sum, ans, ret);
        dfs(root->right, sum, ans, ret);
        ans.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> ans;
        dfs(root, sum, ans, ret);
        return ret;
    }
};