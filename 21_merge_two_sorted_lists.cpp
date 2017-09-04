/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) swap(l1, l2);
        ListNode* u = l1, *p = l2, *q = l2;
        while (u->next != NULL && p != NULL){
            if (p->val >= u->val && p->val <= u->next->val){
                q = p;
                while (q->next != NULL && q->next->val <= u->next->val) q = q->next;
                ListNode* tmp = q->next;
                q->next = u->next;
                u->next = p;
                p = tmp;
                u = q;
            }
            u = u->next;
        }
        if (p) u->next = p;
        return l1;
    }
};