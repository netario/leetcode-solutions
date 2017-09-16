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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head_hi = new ListNode(0), *head_lo = new ListNode(0), *u_hi = head_hi, *u_lo = head_lo;
        while (head) {
            if (head->val < x) {
                u_lo->next = head;
                u_lo = u_lo->next;
            } else {
                u_hi->next = head;
                u_hi = u_hi->next;
            }
            head = head->next;
        }
        u_lo->next = head_hi->next;
        u_hi->next = nullptr;
        head = head_lo->next;
        return head;
    }
};