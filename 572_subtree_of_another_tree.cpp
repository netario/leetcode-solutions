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
    bool checkTree(TreeNode* s, TreeNode* t){
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return checkTree(s->left, t->left) && checkTree(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t) || checkTree(s, t);
    }
};