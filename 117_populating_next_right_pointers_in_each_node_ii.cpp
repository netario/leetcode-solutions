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
        while (root) {
            TreeLinkNode *ptr = nullptr, *nxt = nullptr;
            while (root) {
                if (root->left) {
                    if (!nxt) nxt = root->left;
                    if (ptr) ptr->next = root->left;
                    ptr = root->left;
                }
                if (root->right) {
                    if (!nxt) nxt = root->right;
                    if (ptr) ptr->next = root->right;
                    ptr = root->right;
                }
                root = root->next;
            }
            root = nxt;
        }
    }
};