/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* u = head;
        int len = 0;
        while (u) {
            len ++;
            u = u->next;
        }
        return build(len, head);
    }
private:
    TreeNode* build(int len, ListNode*& u) {
        if (len == 0) return nullptr;
        TreeNode* root = new TreeNode(0);
        root->left = build((len - 1) / 2, u);
        root->val = u->val;
        u = u->next;
        root->right = build(len - 1 - (len - 1) / 2, u);
        return root;
    }
};