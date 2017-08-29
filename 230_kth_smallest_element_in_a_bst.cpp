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
    int inorder(TreeNode* root, int& k) {
        if (!root) return -1;
        int tmp = inorder(root->left, k);
        return !k ? tmp : !--k ? root->val : inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};