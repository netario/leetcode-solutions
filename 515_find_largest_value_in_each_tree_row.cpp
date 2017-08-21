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
    void dfs(TreeNode *root, int dep, vector<int>& ans){
        if (!root) return;
        if (ans.size() <= dep){
            ans.push_back(root->val);
        }else{
            ans[dep] = max(ans[dep], root->val);
        }
        dfs(root->left, dep + 1, ans);
        dfs(root->right, dep + 1, ans);
    }
    public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        dfs(root, 0, ret);
        return ret;
    }
};