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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        while (root || !stk.empty()){
            while (root){
                stk.push(root);
                root = root->left;
            }
            if (!stk.empty()){
                root = stk.top();
                stk.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};