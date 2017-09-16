/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* l = root;
        while (root) {
            if (root->left) root->left->next = root->right ? root->right : nullptr;
            if (root->right && root->next) root->right->next = root->next->left ? root->next->left : nullptr;
            root = root->next ? root->next : l = l->left;
        }
    }
};