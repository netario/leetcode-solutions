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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        if (!root->left) return -1;
        int ret = -1;
        if (root->left->val > root->val && (ret == -1 || root->left->val < ret)) ret = root->left->val;
        if (root->right->val > root->val && (ret == -1 || root->right->val < ret)) ret = root->right->val;
        int tmp = findSecondMinimumValue(root->left);
        if (tmp > root->val && (ret == -1 || tmp < ret)) ret = tmp;
        tmp = findSecondMinimumValue(root->right);
        if (tmp > root->val && (ret == -1 || tmp < ret)) ret = tmp;
        return ret;
    }
};